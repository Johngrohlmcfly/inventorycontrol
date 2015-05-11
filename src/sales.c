#include "pape.h"

void sales(int a){
	int i=0;
	int Flag, Flag2;

	FILE *ptrFile;
	ptrFile = fopen("papeleria.dat","ab");

	if(ptrFile != NULL) {
		printf("\nIngrese el nombre del articulo..: ");
		fflush(stdin);
		getchar();
		fgets(movimientos[a].nombre,100,stdin);
		Flag = strcmp(movimientos[a].nombre,ventas[i].nombre);
		while(Flag != 0){
			i++;
			Flag = strcmp(movimientos[a].nombre,ventas[i].nombre);
		}
		Flag2 = strcmp(movimientos[a].nombre,ventas[i].nombre);
		while(Flag2 != 0){
			i++;
			Flag2 = strcmp(movimientos[a].nombre,bajas[i].nombre);
		}
		if(Flag2==0){
			printf("\nEl producto esta descontinuado...\n\n");
			//break;
		}
		printf("\nCantidad...:");
		scanf("%d",&movimientos[a].cantidad);

		movimientos[a].numArticulo = ventas[i].numArticulo;
		movimientos[a].precio = ventas[i].precioUnitario;
		movimientos[a].monto = movimientos[a].precio*movimientos[a].cantidad;
		movimientos[a].iva = movimientos[a].monto*0.16;
/*
		if(movimientos[a].cantidad ==){
		movimientos[a].descuento = ventas[i].numArticulo;
		}else if(){

		}else if(){

		}

		movimientos[a].subtotal = movimientos[a].monto - movimientos[a].descuento;
		movimientos[a].total = movimientos[a].subtotal + movimientos[a].ivat;
*/
		printf("\nIntroduzca la fecha: ");
			do {
				printf("\nDia: ");
				scanf("%d",&movimientos[a].fventa.dia);
			} while(movimientos[a].fventa.dia > 31 || movimientos[a].fventa.dia < 1);

			do {
				printf("\nMes: ");
				scanf("%d", &movimientos[a].fventa.mes);
			} while(movimientos[a].fventa.mes > 12 || movimientos[a].fventa.mes < 1);

			//do{
			printf("\nAnio: ");
			scanf("%d",&movimientos[a].fventa.anio);
			//}while(recepcion[a].frecepcion.anio>31);

			do {
				printf("\nHora: ");
				scanf("%d", &movimientos[a].fventa.hora);
			} while(movimientos[a].fventa.hora > 24 || movimientos[a].fventa.hora < 0);

			do {
				printf("\nMinuto: ");
				scanf("%d", &movimientos[a].fventa.minuto);
			} while(movimientos[a].fventa.minuto > 59 || movimientos[a].fventa.minuto < 0);

			do{
				printf("\nSegundo: ");
				scanf("%d", &movimientos[a].fventa.segundo);
			}while(movimientos[a].fventa.segundo > 59 || movimientos[a].fventa.segundo < 0);


		fclose(ptrFile);
	} else {
  	printf("Error en la apertura del archivo");
	}

	printf("\n");
}
