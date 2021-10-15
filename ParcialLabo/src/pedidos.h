#ifndef STRUCTORDERS_H_
#define STRUCTORDERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

typedef struct{
	int isEmpty;
	int idPedido;
	int estado;
	char descripcionEstado[50];
	float kilosTotales;
	float kgHdpe;
	float kgLdpe;
	float kgPp;
	int idCliente;
}ePedidos;

/// @fn void InicializarP(ePedidos[], int)
/// @brief Recibe lista de pedidos y tamaño, recorre y lo inicializa en 0.
/// @param lista
/// @param tam
void InicializarP(ePedidos lista[], int tam);
/// @fn int mostrarListaPedidos(ePedidos[], int)
/// @brief Recibe lista de pedidos y el tamaño, la recorre y muestra el contenido.
/// @param lista
/// @param tam
/// @return retorna 1 si se pudo mostrar, en caso contrario retorna 0.
int mostrarListaPedidos(ePedidos lista[], int tam);
/// @fn void mostrarUnPedido(ePedidos)
/// @brief Recibe un elemento de la lista de pedidos y lo muestra.
/// @param unPedido
void mostrarUnPedido(ePedidos unPedido);
/// @fn void validarPorDesc(ePedidos[], int)
/// @brief Recibe lista de pedidos y tamaño. valida estado y asigna descripcion.
/// @param listaP
/// @param tam
void validarPorDesc(ePedidos listaP[], int tam);
/// @fn int ProcesarPedido(ePedidos[], int)
/// @brief Recibe lista de pedidos y tamaño. recorre y valida y procesa los kilos de reciduos reciclados.
/// @param listaP
/// @param tamP
/// @return retorna 1 si se pudo mostrar, en caso contrario retorna 0.
int ProcesarPedido(ePedidos listaP[], int tamP);
/// @fn int validarIdPedido(ePedidos[], int, int)
/// @brief Recibe lista de pedidos, tamaño y id. recorre y compara con el id.
/// @param listaP
/// @param tamP
/// @param id
/// @return retorna 1 si se pudo mostrar, en caso contrario retorna 0.
int validarIdPedido(ePedidos listaP[], int tamP, int id);
/// @fn int cargarTiposPlasticos(ePedidos[], int, int, float)
/// @brief Recibe lista de pedidos, tamaño, id y kgs. Recorre la lista y asigna kg al tipo de reciduo reciclado.
/// @param listaP
/// @param tamP
/// @param id
/// @param kgs
/// @return retorna 1 si se pudo mostrar, en caso contrario retorna 0.
int cargarTiposPlasticos(ePedidos listaP[], int tamP, int id, float kgs);

#endif /* STRUCTORDERS_H_ */
