#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"
#include "inputs.h"


#define TAMCLIENTES 100
#define TAMPEDIDOS 1000
#define TAMTIPOS 3

int main(void) {

	setbuf(stdout,NULL);

	int contadorIdCli;
	int contadorIdPed;
	int opcion;
	int opcionSubMenu;
	eClientes listaClientes[TAMCLIENTES];
	ePedidos listaPedidos[TAMPEDIDOS];
	eLocalidad listaLocalidades[TAMCLIENTES];

	contadorIdCli = 0;
	contadorIdPed = 0;
	Inicializar(listaClientes, TAMCLIENTES);
	InicializarP(listaPedidos, TAMPEDIDOS);

	harcodearCliente(listaClientes, 1, "Grupo Z", "30111122220", "Siempre viva 4000", 2);
	harcodearCliente(listaClientes, 2, "Recolex", "30123456781", "Calle Falsa 123", 1);


	do{
		opcion = MenuPrincipal();
		switch(opcion){
			case 1:
					contadorIdCli++;
					if(AltaCliente(listaClientes, TAMCLIENTES, contadorIdCli)==0)
					{
						printf("Todas las posiciones estan ocupadas.");
					}
					printf("\n");
			break;
			case 2:
					opcionSubMenu = subMenu();
					if(modificarCliente(listaClientes, TAMCLIENTES, opcionSubMenu)==0)
					{
						printf("No hay clientes activos para modificar.");
					}
					printf("\n");
			break;
			case 3:
					if(bajaCliente(listaClientes, TAMCLIENTES)==0)
					{
						printf("No se encontró cliente para dar de baja.");
					}
					printf("\n");
			break;
			case 4:
					contadorIdPed++;
					if(CrearPedido(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS, contadorIdPed, listaLocalidades)==0)
					{
						printf("No se encontró cliente para generar pedido.");
					}
					printf("\n");
			break;
			case 5:
			        if(ProcesarPedido(listaPedidos, TAMPEDIDOS)==0)
			        {
			            printf("No se encontró pedido para procesar.");
			        }
			        printf("\n");
			break;
			case 6:
			        if(imprimirClientesConPedidos(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS, listaLocalidades)==0)
					{
						printf("No hay clientes activos para mostrar.");
					}
					printf("\n");
			break;
			case 7:
			        if(imprimirListaPedisdosPendientes(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS)==0)
					{
						printf("No hay pedidos para mostrar.");
					}
					printf("\n");
			break;
			case 8:
			        if(imprimirPedidosProcesados(listaPedidos, TAMPEDIDOS, listaClientes, TAMCLIENTES)==0)
					{
						printf("No hay pedidos para mostrar.");
					}
					printf("\n");
			break;
			case 9:
			        if(pedidosPorLocalidad(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS, listaLocalidades)==0)
					{
						printf("No hay pedidos pendientes para dicha localidad.");
					}
					printf("\n");
			break;
			case 10:
			        if(promedios(listaClientes, TAMCLIENTES, listaPedidos, TAMPEDIDOS)==0)
					{
						printf("No se puede mostrar promedios.");
					}
					printf("\n");
			break;
			case 11:
			        printf("Gracias por usar la app.");
			        printf("\n");
			break;
			default:
			break;
		}

	}while(opcion==11);


	return EXIT_SUCCESS;
}
