#ifndef STRUCTCLIENTS_H_
#define STRUCTCLIENTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

typedef struct{
	int isEmpty;
	int idCliente;
	char nombreEmpresa[50];
	char cuit[15];
	char direccion[50];
	//char localidad[50];
	int idLocalidad;
}eClientes;
/// @fn void Inicializar(eClientes[], int)
/// @brief recorre estructura de clientes y lo inicializa en 0.
/// @param lista
/// @param tam
void Inicializar(eClientes lista[], int tam);
/// @fn int AltaCliente(eClientes[], int, int)
/// @brief Recibe lista de clientes, tamaño y id, ejecuta el alta en un espacio vacio.
/// @param lista
/// @param tam
/// @param id
/// @return retorna 1 si el alta es correcta y 0 caso contrario.
int AltaCliente(eClientes lista[], int tam, int id);
/// @fn int modificarCliente(eClientes[], int, int)
/// @brief Recibe lista de clientes, tamaño y id, ejecuta la modificación.
/// @param lista
/// @param tam
/// @param opcion
/// @return retorna 1 si el alta es correcta y 0 caso contrario.
int modificarCliente(eClientes lista[], int tam, int opcion);
/// @fn int bajaCliente(eClientes[], int)
/// @brief Recibe lista de clientes y tamaño, ejecuta la baja.
/// @param lista
/// @param tam
/// @return retorna 1 si el alta es correcta y 0 caso contrario.
int bajaCliente(eClientes lista[], int tam);
/// @fn void harcodearCliente(eClientes[], int, char[], char[], char[], char[])
/// @brief Recibe lista de clientes, y ejecuta el harcoder para probar el ABM.
/// @param lista
/// @param id
/// @param empresa
/// @param cuit
/// @param direccion
/// @param localidad
void harcodearCliente(eClientes lista[], int id, char empresa[], char cuit[], char direccion[], int idlocalidad);

#endif /* STRUCTCLIENTS_H_ */
