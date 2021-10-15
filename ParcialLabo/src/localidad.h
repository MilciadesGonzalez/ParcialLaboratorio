#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

typedef struct{
	int idLocalidad;
	char descripcionLocalidad[50];
}eLocalidad;

int menuLocalidad();
void validarPorLocalidad(eLocalidad listaL[], int tam);

#endif /* LOCALIDAD_H_ */
