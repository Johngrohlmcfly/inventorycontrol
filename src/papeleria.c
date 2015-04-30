//Made by <John Hernandez> <johnhndzr@gmail.com>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000

void addproducts(int a);

//struct para fechas de movimientos
struct fecha {
	int dia;
	int mes;
	int anio;
	int hora;
	int minuto;
	int segundo;
} frecepcion, fbaja, fventa;

//struct para recepcion de articulos
struct articulos {
	short flag;

	char nombre[100];
	char presentacion[10];

	int numArticulo;
	int piezaPorCaja;
	int cantidadRecibida;
	int existencia;

	float precioUnitario;
	float precioporcaja;

	struct fecha frecepcion;
} recepcion[SIZE];

//struct para baja de articulos
struct bajaart {
	char nombre[100];

	int numArticulo;

	struct fecha fbaja;
} bajas;

//struct para registro de ventas
struct ventas {
	int cantidad;

	float precio;
	float descuento;
	float iva;
	float subtotal;
	float total;

	struct fecha fventa;
} movimientos;


int main(void) {
	int i, accion, count = 0; //, recepcion;
	int posicion = 0;

	char continuar;

	printf("\n\n----------------------------------------------\n");
	printf("---------------PAPELERIA LUPITA---------------\n");
	printf("----------------------------------------------\n");
	printf("\n---Seleccione del menu la accion a realizar---\n");
	printf("\n---------------------MENU---------------------\n");
	printf("[RECEPCION DE PRODUCTOS]---------------------1\n");
	printf("[BAJA DE PRODUCTOS]--------------------------2\n");
	printf("[VENTA DE PRODUCTOS]-------------------------3\n");
	scanf("%d", &accion);

	if(accion<0 || accion>3){
		do {
			count++;
			printf("\nSeleccion invalida, ingresa un numero valido del menu....\n");
			scanf("%d", &accion);

			if(count==5){
				printf("\nERROR EN LA EJECUCION, -----FIN DEL PROGRAMA-----\n\n");
				break;
			}
		} while(accion < 0 || accion > 3);
	}

	i = 0;

	for(; i < SIZE; i++){
		recepcion[i].flag = 0;
	}

	i = 0;

	switch (accion){
		case 1:
			while(recepcion[posicion].flag != 0){
				posicion++;
			}

			continuar='y';

			addproducts(posicion);
			posicion++;

			printf("\nDesea ingresar mas articulos??...(y/n)\n");
			scanf("%c",&continuar);

			while(continuar == 'y' || continuar == 'Y'){
				addproducts(posicion);

				printf("\nDesea ingresar mas articulos??...(y/n)\n");
				scanf("%c",&continuar);

				posicion++;
			}
			break;
		case 2:
			printf("\nHOLA MUNDO");
		break;
		case 3:
			printf("\nHOLA MUNDO");
		break;
	}

	return 0;
}

//FUNCIONES y PROCEDIMIENTOS
void addproducts(int a){
	FILE *ptrFile;
	ptrFile = fopen("papeleria.dat","a");

	if(ptrFile!=NULL){
	 	fflush(stdin);

	 	printf("\nIntroduzca el nombre del producto: ");

		fgets(recepcion[a].nombre);
	 	fflush(stdin);

		printf("\nIntroduzca el numero de item: ");
	 	scanf("%d",&recepcion[a].numArticulo);

		fflush(stdin);

		printf("\nEn que presentacion?(caja/pieza): ");

		fgets(recepcion[a].presentacion);
	 	fflush(stdin);

		printf("\nCantidad recibida: ");
	 	scanf("%d",&recepcion[a].cantidadRecibida);

		fflush(stdin);

 		if(recepcion[a].presentacion=='caja' || recepcion[a].presentacion=='CAJA' ||recepcion[a].presentacion=='Caja'){
			printf("\nPiezas por caja: ");
			scanf("%d",&recepcion[a].piezaPorCaja);

			fflush(stdin);

			recepcion[a].existencia = recepcion[a].cantidadRecibida*recepcion[a].piezaPorCaja;

			printf("\nIntroduzca el precio del producto: ");
			scanf("%f",&recepcion[a].precioporcaja);

			fflush(stdin);

			recepcion[a].precioUnitario = recepcion[a].precioporcaja/recepcion[a].piezaPorCaja;
		}

		printf("\nIntroduzca el precio del producto: ");
		scanf("%f",&recepcion[a].precioUnitario);
		fflush(stdin);

		printf("\nIntroduzca la fecha de recepcion: ");
		printf("\nDia: ");
		scanf("%d",&recepcion[a].frecepcion.dia);

		printf("\nMes: ");
		scanf("%d",&recepcion[a].frecepcion.mes);

		printf("\nAnio: ");
		scanf("%d",&recepcion[a].frecepcion.anio);

		printf("\nHora: ");
		scanf("%d",&recepcion[a].frecepcion.hora);

		printf("\nMinuto: ");
		scanf("%d",&recepcion[a].frecepcion.minuto);

		printf("\nSegundo: ");
		scanf("%d",&recepcion[a].frecepcion.segundo);

		fwrite(&recepcion[a],sizeof(articulos),1,ptrFile);

		fclose(ptrFile);
	} else {
  	printf("Error en la apertura del archivo");
	}
	printf("\n");
}
