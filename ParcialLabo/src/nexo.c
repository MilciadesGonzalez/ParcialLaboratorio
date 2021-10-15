#include "nexo.h"
#define PENDIENTE 0
#define COMPLETADO 1
#define TRUE 0
#define FALSE 1

int CrearPedido(eClientes listaC[], int tamC, ePedidos listaP[], int tamP, int idPed, eLocalidad listaL[])
{
	int flag;
	flag = 0;
	int idCli;

	mostrarListaClientes(listaC, tamC, listaL);
	idCli = getInt("Ingrese ID del cliente para crear pedido: ");
	for(int i=0; i<tamP; i++)
	{
		if (listaP[i].isEmpty == TRUE && validarArray(listaC, tamC, idCli) == 1)
		{
			listaP[i].idPedido = idPed;
			listaP[i].kilosTotales = getFloat("Ingrese kilos totales: ");
			listaP[i].idCliente = idCli;
			listaP[i].estado = PENDIENTE;
			listaP[i].isEmpty = FALSE;
			printf("\nPedido generado correctamente.\n");

			flag = 1;
			break;
		}
	}
	return flag;
}
int validarArray(eClientes listaC[], int tamC, int idCli)
{
	int flag;
	flag = 0;

	for(int i=0; i<tamC; i++)
	{
		if(listaC[i].idCliente==idCli)
		{
			flag = 1;
		}
	}


	return flag;
}
int imprimirClientesConPedidos(eClientes listaC[], int tamC, ePedidos listaP[], int tamP, eLocalidad listaL[])
{
 	int flag;
 	eAuxPedido aux[tamP];
	InicializarAuxPed(listaP, tamP, aux);
	flag = 0;

	printf("ID \t Empresa \t\t Cuit \t\t Direccion \t\t Localidad \t Q.Ped.Pendientes\n");
	for(int i=0; i<tamC; i++)
	{
		for(int j=0; j<tamP; j++)
		{
			if(listaC[i].isEmpty==FALSE && listaC[i].idCliente==listaP[j].idCliente && listaP[j].estado==PENDIENTE)
			{
				recorrer(listaP, tamP, aux);
				validarPorLocalidad(listaL, tamC);
				printf("%-8d %-20s %-20s %-20s %-20s %d\n", listaC[i].idCliente,
															listaC[i].nombreEmpresa,
															listaC[i].cuit,
															listaC[i].direccion,
															listaL[i].descripcionLocalidad,
															//listaC[i].localidad,
															aux[j].contador);
				flag = 1;
				break;
			}
		}
	}

	return flag;
}
void InicializarAuxPed(ePedidos lista[], int tam, eAuxPedido* auxPed)
{
	for(int i=0; i<tam; i++)
	{
		auxPed[i].contador = 0;
		auxPed[i].acumulador = 0;
		auxPed[i].id = lista[i].idCliente;
	}
}
//------------------------------------------------------------------------
void recorrer(ePedidos lista[], int tam, eAuxPedido aux[])
{
    for(int i=0; i<tam;i++)
	{
	    contar(lista[i], tam, aux);
	}
}
void contar(ePedidos unPedido, int tam, eAuxPedido aux[])
{
	for(int i=0; i<tam; i++)
	{
		if(aux[i].id == unPedido.idPedido)
		{
			aux[i].contador++;
		}
	}
}
//-------------------------------------------------------------------------
int imprimirListaPedisdosPendientes(eClientes listaC[], int tamC, ePedidos listaP[], int tamP)
{
	int flag;
	flag = 0;

	printf("Estado Pedido \t Cuit \t\t Direccion \t\t Q.Kilos\n");
	for(int i=0; i<tamP; i++)
	{
		for(int j=0; j<tamC; j++)
		{
			if(listaP[i].isEmpty==FALSE && listaC[j].isEmpty==FALSE && listaP[i].estado==PENDIENTE)
			{
				validarPorDesc(listaP, tamP);
				if(listaP[i].idCliente==listaC[j].idCliente)
				{
					printf("%-15s %-15s %-15s \t %6.2f\n",
														listaP[i].descripcionEstado,
														listaC[j].cuit,
														listaC[j].direccion,
														listaP[i].kilosTotales);
					flag = 1;
					break;
				}
			}
		}
	}
	return flag;
}
int imprimirPedidosProcesados(ePedidos listaP[], int tamP, eClientes listaC[], int tamC)
{
	int flag;
	flag = 0;
	printf("Estado Pedido \t Cuit \t\t Direccion \t\t Q.Kg.HDPE \t Q.Kg.LDPE \t Q.Kg.PP\n");
	for(int i=0; i<tamP; i++)
	{
		for(int j=0; j<tamC; j++)
		{
			if (listaP[i].isEmpty == FALSE && listaC[j].isEmpty == FALSE && listaP[i].estado==COMPLETADO)
			{
				validarPorDesc(listaP, tamP);
				if (listaP[i].idCliente == listaC[j].idCliente)
				{
					printf("%-15s %-15s %-15s %16.2f %16.2f %16.2f\n",
																	listaP[i].descripcionEstado,
																	listaC[j].cuit,
																	listaC[j].direccion,
																	listaP[i].kgHdpe,
																	listaP[i].kgLdpe,
																	listaP[i].kgPp);
					flag = 1;
					break;
				}
			}
		}
	}

	return flag;
}
int pedidosPorLocalidad(eClientes listaC[], int tamC, ePedidos listaP[], int tamP, eLocalidad listaL[])
{
	int flag;
	eAuxLocalidad aux[tamP];
	InicializarAuxLoc(listaP, tamP, aux);
	flag = 0;

    imprimirClientesConPedidos(listaC, tamC, listaP, tamP, listaL);
	pedirLocalidad(aux, tamC);

	for(int i=0; i<tamP; i++)
	{
		if (listaP[i].isEmpty == FALSE)
		{
			contarLocalidad(listaC, tamC, aux, listaP, tamP, listaL);
			printf("%d\n", aux[i].contador);
			flag = 1;
			break;
		}
	}
	return flag;
}
void InicializarAuxLoc(ePedidos lista[], int tamP, eAuxLocalidad* auxPed)
{
	for(int i=0; i<tamP; i++)
	{
		auxPed[i].contador = 0;
		auxPed[i].acumulador = 0;
		auxPed[i].id = lista[i].estado;
	}
}
void contarLocalidad(eClientes lista[], int tamC, eAuxLocalidad* aux, ePedidos listaP[], int tamP, eLocalidad listaL[])
{
	for(int i=0; i<tamP;i++)
	{
		for(int j=0; j<tamP; j++)
		{
			for(int k=0; k<tamC; k++)
			{
				if(aux[i].id==listaP[j].estado && strcpy(aux[i].descripcion, listaL[k].descripcionLocalidad)==0)
				{
					aux[i].contador++;
				}
			}
		}
	}
}
void pedirLocalidad(eAuxLocalidad aux[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		getStringSinVal("Ingrese localidad: ", aux[i].descripcion);
		break;
	}
}
int promedios(eClientes listaC[], int tamC, ePedidos listaP[], int tamP)
{
    int flag;
    float promedio;
    eAuxPedido aux[tamP];
    InicializarAuxPed(listaP, tamP, aux);
	flag = 0;

	printf("ID \t Empresa \t\t Cuit \t\t Kgs.Prom.PP.\n");
	for(int i=0; i<tamC; i++)
	{
		for(int j=0; j<tamP; j++)
		{
			if(listaC[i].isEmpty==FALSE && listaC[i].idCliente==listaP[j].idCliente && listaP[j].estado==PENDIENTE)
			{
				recorrerPed(listaP, tamP, aux);
				promedio = aux[j].acumulador / aux[j].contador;
				printf("%-8d %-20s %-20s %.2f\n", listaC[i].idCliente,
															listaC[i].nombreEmpresa,
															listaC[i].cuit,
															promedio);
				flag = 1;
				break;
			}
		}
	}
	return flag;
}
//------------------------------------------------------------------------
void recorrerPed(ePedidos lista[], int tam, eAuxPedido aux[])
{
    for(int i=0; i<tam;i++)
	{
	    contarCli(lista[i], tam, aux);
	}
}
void contarCli(ePedidos unPedido, int tam, eAuxPedido aux[])
{
	for(int i=0; i<tam; i++)
	{
		if(aux[i].id == unPedido.idCliente)
		{
			aux[i].contador++;
			aux[i].acumulador += unPedido.kgPp;
		}
	}
}
//-------------------------------------------------------------------------
void InicializarLocalidad(eClientes listaC[], int tamC, eLocalidad listaL[])
{
	for(int i=0; i<tamC; i++)
	{
		listaL[i].idLocalidad = listaC[i].idLocalidad;
	}
}
int mostrarListaClientes(eClientes listaC[], int tamC, eLocalidad listaL[])
{
	int flag;
	flag = 0;
	printf("ID \t Empresa \t\t Cuit \t\t Direccion \t\t Localidad\n");
	for(int i=0; i<tamC; i++)
	{
		if(listaC[i].isEmpty==FALSE)
		{
			validarPorLocalidad(listaL, tamC);
			mostrarUnCliente(listaC[i], listaL[i]);
			flag = 1;
		}
	}
	return flag;
}
void mostrarUnCliente(eClientes unCliente, eLocalidad unaLocalidad)
{
	printf("%-8d %-20s %-20s %-20s %-20s\n", unCliente.idCliente,
											unCliente.nombreEmpresa,
											unCliente.cuit,
											unCliente.direccion,
											unaLocalidad.descripcionLocalidad);
}
