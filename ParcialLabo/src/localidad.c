#include "localidad.h"


int menuLocalidad()
{
	int op;

	printf("Selecione localidad:\n");
	printf("1. Caba.\n");
	printf("2. Lanus.\n");
	printf("3. Avellaneda.\n");
	printf("4. Otros.\n");
	printf("\n");
	op = getInt("Ingrese opcion: ");
	printf("\n");

	return op;
}
void validarPorLocalidad(eLocalidad listaL[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		if(listaL[i].idLocalidad==1)
		{
			strcpy(listaL[i].descripcionLocalidad, "Caba");
		}
		else if(listaL[i].idLocalidad==2)
		{
			strcpy(listaL[i].descripcionLocalidad, "Lanus");
		}
		else if(listaL[i].idLocalidad==3)
		{
			strcpy(listaL[i].descripcionLocalidad, "Avellaneda");
		}
		else if(listaL[i].idLocalidad==4)
		{
			strcpy(listaL[i].descripcionLocalidad, "Otros");
		}
	}
}

