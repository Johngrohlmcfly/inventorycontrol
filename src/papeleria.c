//Made by <John Hernandez> <johnhndzr@gmail.com>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addproducts(int a);

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
	int noarticulo;
	char presentacion[10];
	int piezaxcaja;
	int cantidadrecibida;
	int existencia;
	float preciounitario;
	float precioporcaja;
	struct fecha frecepcion;
}recepcion[10000],auxiliar[10000]={NULL};

//struct para baja de articulos
struct bajaart{
	char nombre[100];
	int noarticulo;
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
	int accion, count=0;//para la validacion del menu

	int posicion;
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
				while(recepcion[posicion]!=auxiliar[posicion]){
				posicion++;
			}
				continuar='y';
				addproducts(posicion);
				posicion++;
				printf("\nDesea ingresar mas articulos??...(y/n)\n");
				scanf("%c",&continuar);
				while(continuar=='y'||continuar=='Y'){
				addproducts(posicion);
				printf("\nDesea ingresar mas articulos??...(y/n)\n");
				scanf("%c",&continuar);
				posicion++;
			}
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

void addproducts(int a){
	FILE *ptrFile;
	ptrFile=fopen("papeleria.dat","a");

	if(ptrFile!=NULL){
 	  	 fflush(stdin);
 		 printf("\nIntroduzca el nombre del producto: ");
 		 fgets(recepcion[a].nombre,sizeof(recepcion[a].nombre),stdin);
 		 fflush(stdin);
 		 printf("\nIntroduzca el numero de item: ");
 		 scanf("%d",&recepcion[a].noarticulo);
 		 fflush(stdin);
 		 printf("\nEn que presentacion?(caja/pieza): ");
 		 fgets(recepcion[a].nombre,sizeof(recepcion[a].nombre),stdin);
 		 fflush(stdin);
 		 printf("\nCantidad recibida: ");
 		 scanf("%d",&recepcion[a].cantidadrecibida); 	
 		 fflush(stdin);
 		 if(recepcion[a].presentacion == 'caja'||recepcion[a].presentacion == 'CAJA'||recepcion[a].presentacion == 'Caja'){
			printf("\nPiezas por caja: ");
 			 scanf("%d",&recepcion[a].piezaxcaja);
 		 	recepcion[a].existencia=recepcion[a].cantidadrecibida*recepcion[a].piezaxcaja;
 		 	fflush(stdin);
 		 	printf("\nIntroduzca el precio del producto: ");
 			 scanf("%f",&recepcion[a].precioporcaja);
 			 recepcion[a].preciounitario=recepcion[a].precioporcaja/recepcion[a].piezaxcaja;
 		 }
 		 fflush(stdin);
 		 printf("\nIntroduzca el precio del producto: ");
 		 scanf("%f",&recepcion[a].preciounitario);
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
      	 fwrite(&recepcion[a],sizeof(recepcion[a]),1,ptrFile);
      	fclose(ptrFile);
      }
    else
    	printf("Error en la apertura del archivo\n\n");
  }