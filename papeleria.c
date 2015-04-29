//Made by <John Hernandez> <johnhndzr@gmail.com>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addproducts(int a[]);

//struct para fechas de movimientos
	struct fecha{
		int dia;
		int mes;
		int anio;
		int hora;
		int minuto;
		int segundo;
	}frecepcion, fbaja, fventa;

//struct para recepcion de articulos
	struct articulos{
	char nombre[100];
	int numarticulo;
	char presentacion[10];
	int piezaxcaja;
	int cantidadrecibida;
	int existencia;
	float preciounitario;
	float precioporcaja;
	struct fecha frecepcion;
}recepcion[10000]={0};

//struct para baja de articulos
struct bajaart{
	char nombre[100];
	int numarticulo;
	struct fecha fbaja;
}bajas;

//struct para registro de ventas
struct ventas{
	int cantidad;
	float precio;
	float descuento;
	float iva;
	float subtotal;
	float total;
	struct fecha fventa;
}movimientos;



int main(int argc, char const *argv[])
{
	int recepcion, i, accion, count=0;
	int posicion, ix;
	char continuar;

	printf("\n\n----------------------------------------------\n");
	printf("---------------PAPELERIA LUPITA---------------\n");
	printf("----------------------------------------------\n");
	printf("\n---Seleccione del menu la accion a realizar---\n");
	printf("\n---------------------MENU---------------------\n");
	printf("[RECEPCION DE PRODUCTOS]---------------------1\n");
	printf("[BAJA DE PRODUCTOS]--------------------------2\n");
	printf("[VENTA DE PRODUCTOS]-------------------------3\n");
	scanf("%d",&accion);

	if(accion<0 || accion>3){
		do{
			count++;
			printf("\nSeleccion invalida, ingresa un numero valido del menu....\n");
			scanf("%d",&accion);
			if(count==5){
			printf("\nERROR EN LA EJECUCION, -----FIN DEL PROGRAMA-----\n\n");
			break;
			}
		}while(accion<0 || accion>3);
	};

	switch (accion){
		
		case 1:{
			  	do{
				posicion++;
				ix++;
				}while(recepcion[posicion]!=0);
				continuar='y';
				addproducts(recepcion[10000]);
				printf("\nDesea ingresar mas articulos??...(y/n)\n");
				scanf("%c",&continuar);
			};
			break;

		case 2:{
			printf("\nHOLA MUNDO");

		};
		break;

		case 3:{
			printf("\nHOLA MUNDO");

		};
		break;

	}

	return 0;
}



//FUNCIONES y PROCEDIMIENTOS

void addproducts(int a[]){
	FILE *ptrFile;
	ptrFile=fopen("papeleria.dat","a");
	if(ptrFile!=NULL){
 	  	 fflush(stdin);
 		 printf("\nIntroduzca el nombre del producto: ");
 		 fgets(recepcion[posicion].nombre);
 		 fflush(stdin);
 		 printf("\nIntroduzca el numero de item: ");
 		 scanf("%d",&recepcion[posicion].numarticulo);
 		 fflush(stdin);
 		 printf("\nEn que presentacion?(caja/pieza): ");
 		 fgets(recepcion[posicion].presentacion);
 		 fflush(stdin);
 		 printf("\nCantidad recibida: ");
 		 scanf("%d",&recepcion[posicion].cantidadrecibida); 	
 		 fflush(stdin);
 		 if(recepcion[posicion].presentacion=='caja'||recepcion[posicion].presentacion=='CAJA'||recepcion[posicion].presentacion=='Caja'){
			printf("\nPiezas por caja: ");
 			 scanf("%d",&recepcion[posicion].piezaxcaja);
 		 	recepcion[posicion].existencia=recepcion[posicion].cantidadrecibida*recepcion[posicion].piezaxcaja;
 		 	fflush(stdin);
 		 	printf("\nIntroduzca el precio del producto: ");
 			 scanf("%f",&recepcion[posicion].precioporcaja);
 			 recepcion[posicion].preciounitario=recepcion[posicion].precioporcaja/recepcion[posicion].piezaxcaja;
 		 }
 		 fflush(stdin);
 		 printf("\nIntroduzca el precio del producto: ");
 		 scanf("%f",&recepcion[posicion].preciounitario);
 		 fflush(stdin);
 		 printf("\nIntroduzca la fecha de recepcion: ");
 		 printf("\nDia: ");
 		 scanf("%d",&recepcion[posicion].frecepcion.dia);
 		 printf("\nMes: ");
 		 scanf("%d",&recepcion[posicion].frecepcion.mes);
 		 printf("\nAnio: ");
 		 scanf("%d",&recepcion[posicion].frecepcion.anio);
 		 printf("\nHora: ");
 		 scanf("%d",&recepcion[posicion].frecepcion.hora);
 		 printf("\nMinuto: ");
 		 scanf("%d",&recepcion[posicion].frecepcion.minuto);
 		 printf("\nSegundo: ");
 		 scanf("%d",&recepcion[posicion].frecepcion.segundo);
      	 fwrite(&recepcion[posicion],sizeof(articulos),1,ptrFile);
      	}
      	fclose(ptrFile);
    else
    	printf("Error en la apertura del archivo");
  }
	printf("\n");
}