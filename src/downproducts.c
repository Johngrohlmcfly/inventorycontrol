#include "pape.h"

void downproducts(){
	int i = 0;
	int Flag, a = 0;

	FILE *ptrFile;
	ptrFile = fopen("papeleria.dat","rb");

	if(ptrFile != NULL) {
		printf("\nIngrese el nombre del articulo que se dara de baja...: ");

		fflush(stdin);
		getchar();
		fgets(bajas[a].nombre,100,stdin);

		fread(&recepcion, sizeof(recepcion[i]), SIZE, ptrFile);

		Flag = strcmp(bajas[a].nombre,recepcion[i].nombre);
		while(Flag != 0){
			i++;
			Flag = strcmp(bajas[a].nombre,recepcion[i].nombre);
		}
		bajas[a].numArticulo = recepcion[i].numArticulo;
		printf("\nIntroduzca la fecha de baja: ");
			do {
				printf("\nDia: ");
				scanf("%d",&bajas[a].fbaja.dia);
			} while(bajas[a].fbaja.dia > 31 || bajas[a].fbaja.dia < 1);

			do {
				printf("\nMes: ");
				scanf("%d", &bajas[a].fbaja.mes);
			} while(bajas[a].fbaja.mes > 12 || bajas[a].fbaja.mes < 1);

			//do{
			printf("\nAnio: ");
			scanf("%d",&bajas[a].fbaja.anio);
			//}while(recepcion[a].frecepcion.anio>31);

			do {
				printf("\nHora: ");
				scanf("%d", &bajas[a].fbaja.hora);
			} while(bajas[a].fbaja.hora > 24 || bajas[a].fbaja.hora < 0);

			do {
				printf("\nMinuto: ");
				scanf("%d", &bajas[a].fbaja.minuto);
			} while(bajas[a].fbaja.minuto > 59 || bajas[a].fbaja.minuto < 0);

			do{
				printf("\nSegundo: ");
				scanf("%d", &bajas[a].fbaja.segundo);
			}while(bajas[a].fbaja.segundo > 59 || bajas[a].fbaja.segundo < 0);
		fclose(ptrFile);
	} else {
  	printf("Error en la apertura del archivo");
	}

	printf("\n");
}
