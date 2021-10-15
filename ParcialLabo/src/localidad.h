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
/// @fn int menuLocalidad()
/// @brief Muestra menu de localidades disponibles.
/// @return retorna opcion elejida.
int menuLocalidad();
/// @fn void validarPorLocalidad(eLocalidad[], int)
/// @brief compara id de localidad y asigna descripcion delocalidad.
/// @param listaL
/// @param tam
void validarPorLocalidad(eLocalidad listaL[], int tam);

#endif /* LOCALIDAD_H_ */
