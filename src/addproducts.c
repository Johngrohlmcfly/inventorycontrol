#include "pape.h"

void addproducts(int a){
	int i, mark, flag = 0;

	FILE *ptrFile;
	ptrFile = fopen("papeleria.dat","ab");

	if(ptrFile != NULL){
	 	printf("\nIntroduzca el nombre del producto: ");
		getchar();
		fgets(recepcion[a].nombre,100,stdin);

		printf("\nIntroduzca el numero de item: ");
	 	scanf("%d",&recepcion[a].numArticulo);

		//fflush(stdin);

		printf("\nEn que presentacion?(caja/pieza): ");

		//fgets(recepcion[a].presentacion,sizeof(recepcion[a].presentacion),stdin);
		scanf("%s",recepcion[a].presentacion);

		printf("\nCantidad recibida: ");
	 	scanf("%d",&recepcion[a].cantidadRecibida);

 		if(strcmp("caja",recepcion[a].presentacion)==0 || strcmp("Caja",recepcion[a].presentacion)==0 ||strcmp("CAJA",recepcion[a].presentacion)==0){
			printf("\nPiezas por caja: ");
			scanf("%d",&recepcion[a].piezaPorCaja);

			recepcion[a].existencia = recepcion[a].cantidadRecibida*recepcion[a].piezaPorCaja;

			printf("\nIntroduzca el precio del producto(por caja): ");
			scanf("%f",&recepcion[a].precioporcaja);

			recepcion[a].precioUnitario = recepcion[a].precioporcaja/recepcion[a].piezaPorCaja;

			printf("\nIntroduzca la fecha de recepcion: ");

			do {
				printf("\nDia: ");
				scanf("%d",&recepcion[a].frecepcion.dia);
			} while(recepcion[a].frecepcion.dia > 31 || recepcion[a].frecepcion.dia < 1);

			do {
				printf("\nMes: ");
				scanf("%d",&recepcion[a].frecepcion.mes);
			} while(recepcion[a].frecepcion.mes > 12 || recepcion[a].frecepcion.mes < 1);

			//do{
			printf("\nAnio: ");
			scanf("%d",&recepcion[a].frecepcion.anio);
			//}while(recepcion[a].frecepcion.anio>31);

			do {
				printf("\nHora: ");
				scanf("%d", &recepcion[a].frecepcion.hora);
			} while(recepcion[a].frecepcion.hora > 24 || recepcion[a].frecepcion.hora < 0);

			do {
				printf("\nMinuto: ");
				scanf("%d",&recepcion[a].frecepcion.minuto);
			} while(recepcion[a].frecepcion.minuto > 59 || recepcion[a].frecepcion.minuto < 0);

			do {
				printf("\nSegundo: ");
				scanf("%d", &recepcion[a].frecepcion.segundo);
			} while(recepcion[a].frecepcion.segundo > 59 || recepcion[a].frecepcion.segundo < 0);

			fwrite(&recepcion[a], sizeof(recepcion), 1, ptrFile);
	 } else {
			printf("\nIntroduzca el precio del producto: ");
			scanf("%f", &recepcion[a].precioUnitario);
			fflush(stdin);

			printf("\nIntroduzca la fecha de recepcion: ");
			do {
				printf("\nDia: ");
				scanf("%d",&recepcion[a].frecepcion.dia);
			} while(recepcion[a].frecepcion.dia > 31 || recepcion[a].frecepcion.dia < 1);

			do {
				printf("\nMes: ");
				scanf("%d", &recepcion[a].frecepcion.mes);
			} while(recepcion[a].frecepcion.mes > 12 || recepcion[a].frecepcion.mes < 1);

			//do{
			printf("\nAnio: ");
			scanf("%d",&recepcion[a].frecepcion.anio);
			//}while(recepcion[a].frecepcion.anio>31);

			do {
				printf("\nHora: ");
				scanf("%d", &recepcion[a].frecepcion.hora);
			} while(recepcion[a].frecepcion.hora > 24 || recepcion[a].frecepcion.hora < 0);

			do {
				printf("\nMinuto: ");
				scanf("%d", &recepcion[a].frecepcion.minuto);
			} while(recepcion[a].frecepcion.minuto > 59 || recepcion[a].frecepcion.minuto < 0);

			do{
				printf("\nSegundo: ");
				scanf("%d", &recepcion[a].frecepcion.segundo);
			}while(recepcion[a].frecepcion.segundo > 59 || recepcion[a].frecepcion.segundo < 0);

			//THIS PART ITS GOING TO SAVE THE DATA IN THE SALES STRUCTURE FOR CREATE AN ACUMULATE INVENTORY
			//THE OTHER ARRAY ONE WILL BE SAVE THE HISTORY OF RECEPTIONS.

			for(i=0; i==a; i++) {
				mark = strcmp(recepcion[a].nombre, ventas[i].nombre);
				flag++;
				if(mark==0){
					break;
				}
			}

			if (mark == 0) {
				strcpy(ventas[a].nombre, recepcion[a].nombre);

				ventas[flag].numArticulo = recepcion[a].numArticulo;
				ventas[flag].existencia = ventas[flag].existencia+recepcion[a].existencia;
				ventas[flag].precioporcaja = recepcion[a].precioporcaja;
				ventas[flag].precioUnitario = recepcion[a].precioUnitario;
				ventas[flag].piezaPorCaja = recepcion[a].piezaPorCaja;
			} else {
				strcpy(ventas[a].nombre, recepcion[a].nombre);

				ventas[a].numArticulo = recepcion[a].numArticulo;
				ventas[a].existencia = recepcion[a].existencia;
				ventas[a].precioporcaja = recepcion[a].precioporcaja;
				ventas[a].precioUnitario = recepcion[a].precioUnitario;
				ventas[a].piezaPorCaja = recepcion[a].piezaPorCaja;
			}

			fwrite(&recepcion[a],sizeof(recepcion),1,ptrFile);
		}
		fclose(ptrFile);
 	} else {
  	printf("Error en la apertura del archivo");
	}
	printf("\n");
}
