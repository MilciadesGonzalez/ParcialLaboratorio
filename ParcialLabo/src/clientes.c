#include "clientes.h"
#include "inputs.h"
#define TRUE 0
#define FALSE 1

void Inicializar(eClientes lista[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		lista[i].isEmpty = TRUE;
	}
}
int AltaCliente(eClientes lista[], int tam, int id)
{
	int flag;
	int opLocalidad;
	flag = 0;

	for (int i = 0; i < tam; i++)
	{
		if (lista[i].isEmpty == TRUE)
		{
			lista[i].idCliente = id;
			getStringSinVal("Ingrese nombre de la empresa: ", lista[i].nombreEmpresa);
			pedirCadenaSoloNumeros("Ingrese cuit de la empresa(sin guiones): ", lista[i].cuit);
			getStringSinVal("Ingrese direccion: ", lista[i].direccion);
			opLocalidad = menuLocalidad();
			lista[i].idLocalidad = opLocalidad;
			//getStringSinVal("Ingrese localidad: ", lista[i].localidad);
			lista[i].isEmpty = FALSE;

			flag = 1;
			break;
		}
	}
	return flag;
}
int modificarCliente(eClientes lista[], int tam, int opcion)
{
	int flag;
	int idCli;
	int opLocalidad;

	mostrarListaClientes(lista, tam);
	printf("\n");
	idCli = getInt("Ingrese Id del cliente a modificar: ");

	flag = 0;

	for(int i=0; i<tam; i++)
	{
		if(lista[i].isEmpty==FALSE && lista[i].idCliente==idCli)
		{
			switch(opcion)
			{
				case 1:
					getStringSinVal("Ingrese nueva direccion: ", lista[i].direccion);
					flag = 1;
				break;
				case 2:
					opLocalidad = menuLocalidad();
					lista[i].idLocalidad = opLocalidad;
					//getStringSinVal("Ingrese nueva localidad: ", lista[i].localidad);
					flag = 1;
				break;
			}
			break;
		}
	}
	return flag;
}
int bajaCliente(eClientes lista[], int tam)
{

	mostrarListaClientes(lista, tam);
	printf("\n");

	int opcion;
	int flag;
	char res;

	flag = 0;

	opcion = getInt("Ingrese ID del cliente a dar de baja: ");

	for(int i=0; i<tam; i++)
	{
		if(lista[i].isEmpty==FALSE && lista[i].idCliente==opcion)
		{
			res = getChar("\nConfirma la eliminacion.? (s/n): ");
			if(res=='s')
			{
				lista[i].isEmpty = TRUE;
				printf("Cliente eliminado correctamente.\n");
				flag = 1;
				break;
			}
			flag = 1;
			break;
		}

	}
	return flag;
}
void harcodearCliente(eClientes lista[], int id, char empresa[], char cuit[], char direccion[], int idlocalidad)
{

		lista[id].isEmpty = 1;
		lista[id].idCliente = id;
		strcpy(lista[id].nombreEmpresa, empresa);
		strcpy(lista[id].cuit, cuit);
		strcpy(lista[id].direccion, direccion);
		lista[id].idLocalidad = idlocalidad;
}


