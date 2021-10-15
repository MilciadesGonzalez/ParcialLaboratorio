#include "pedidos.h"
#define TRUE 0
#define FALSE 1
#define PENDIENTE 0
#define COMPLETADO 1

void InicializarP(ePedidos lista[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		lista[i].isEmpty = 0;
	}
}
int mostrarListaPedidos(ePedidos lista[], int tam)
{
	int flag;
	flag = 0;
	printf("ID \t Estado de Pedido \t Kilos Totales\n");
	for(int i=0; i<tam; i++)
	{
		if(lista[i].isEmpty==FALSE)
		{
			validarPorDesc(lista, tam);
			mostrarUnPedido(lista[i]);
			flag = 1;
		}
	}
	return flag;
}
void mostrarUnPedido(ePedidos unPedido)
{
	printf("%-10d %-18s %10.2f\n",unPedido.idPedido,
								unPedido.descripcionEstado,
								unPedido.kilosTotales);
}
void validarPorDesc(ePedidos listaP[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		if(listaP[i].estado==0)
		{
			strcpy(listaP[i].descripcionEstado, "PENDIENTE");
		}
		else if(listaP[i].estado==1)
		{
			strcpy(listaP[i].descripcionEstado, "COMPLETADO");
		}
	}
}
int ProcesarPedido(ePedidos listaP[], int tamP)
{
    int flag;
    int idPed;
    char res;
    int opTipo;
    int valId;
    float kgs;

    flag = 0;

    for(int i=0; i<tamP; i++)
	{
		if(listaP[i].isEmpty==FALSE && listaP[i].estado==PENDIENTE)
		{
		    mostrarListaPedidos(listaP, tamP);
			idPed = getInt("Ingrese ID del pedido a procesar: ");
			valId = validarIdPedido(listaP, tamP, idPed);
			while(valId==0)
			{
			    mostrarListaPedidos(listaP, tamP);
			    idPed = getInt("Idinvalido.Reingrese ID del pedido: ");
			    valId = validarIdPedido(listaP, tamP, idPed);
			}

			do{
			    opTipo = subMenuTipo();
		        kgs = getFloat("Ingrese kgs reciclados: ");
		        cargarTiposPlasticos(listaP, tamP, opTipo, kgs);

		        res = getChar("Quiere seguir ingresando.? s/n: ");
		    }while(res=='s');
		    listaP[i].estado = COMPLETADO;
			validarPorDesc(listaP, tamP);
			flag = 1;
			break;
		}
	}

    return flag;

}
int validarIdPedido(ePedidos listaP[], int tamP, int id)
{
    int flag;
    flag = 0;

    for(int i=0; i<tamP; i++)
    {
        if(listaP[i].idPedido==id)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}
int cargarTiposPlasticos(ePedidos listaP[], int tamP, int id, float kgs)
{
    int flag;
    flag = 0;

    for(int i=0; i<tamP; i++)
    {
        if(id==1)
        {
            listaP[i].kgHdpe = kgs;
            flag = 1;
            break;
        }
        else if(id==2)
            {
                listaP[i].kgLdpe = kgs;
                flag = 1;
                break;
            }
            else if(id==3)
            {
                listaP[i].kgPp = kgs;
                flag = 1;
                break;
            }
    }

    return flag;
}
