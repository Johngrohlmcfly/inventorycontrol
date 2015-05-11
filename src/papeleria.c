//Made by <John Hernandez> <johnhndzr@gmail.com> & <Sinhue Valencia> <sierisimo@gmail.com>
#include "pape.h"

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
	printf("[VENTA DE PRODUCTOS]-------------------------3\n\n");
	printf("Su seleccion: ");

	scanf("%d", &accion);

	if(accion < 0 || accion > 3){
		do {
			count++;
			printf("\nSeleccion invalida, ingresa un numero valido del menu....\n");
			scanf("%d", &accion);

			if(count == 5){
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
		//FASE 1 MAKE AN ARRAY FOR THE INVENTORY OF ALL PRODUCTS
		case 1:
			while(recepcion[posicion].flag != 0){
				posicion++;
			}

			continuar = 'n';

			addproducts(posicion);
			posicion++;

			printf("\nDesea ingresar mas articulos??...(y/n)\n");
			do {
				continuar = getc(stdin);
			} while(continuar != EOF && !(continuar == 'y' || continuar == 'Y' || continuar == 'n' || continuar == 'N'));

			while(continuar == 'y' || continuar == 'Y'){
				addproducts(posicion);

				printf("\nDesea ingresar mas articulos??...(y/n)\n");
				scanf("%c",&continuar);

				posicion++;
			}
			break;
		//FASE 2, MAKE AN DATABASE FOR DISCONTINUATED PRODUCTS
		case 2:
		//ESTE APROACH DEBE IRSE DENTRO DEL PROCEDIMIENTO
			while(bajas[posicion].flag != 0){
				posicion++;
			}

			continuar = 'n';

			downproducts();

			printf("\nDesea dar de baja mas articulos??...(y/n)\n");
			do {
				continuar = getc(stdin);
			} while(continuar != EOF && !(continuar == 'y' || continuar == 'Y' || continuar == 'n' || continuar == 'N'));

			while(continuar == 'y' || continuar == 'Y'){

				printf("\nDesea dar de baja mas articulos??...(y/n)\n");
				scanf("%c",&continuar);

				continuar = 'n';

				downproducts(posicion);
				posicion++;
			}
			break;
		// FASE 3, SALES!, THIS PART GOING TO DISCOUNT THE PRODUCTS OF INVENTORY & CHECK IF THE ITEM ISNT DISCONTINUED
		case 3:
			while(movimientos[posicion].flag != 0){
				posicion++;
			}

			continuar = 'n';

			sales(posicion);

			printf("\nDesea continuar??...(y/n)\n");
			do {
				continuar = getc(stdin);
			} while(continuar != EOF && !(continuar == 'y' || continuar == 'Y' || continuar == 'n' || continuar == 'N'));

			while(continuar == 'y' || continuar == 'Y'){

				printf("\nDesea continuar??...(y/n)\n");
				scanf("%c",&continuar);

				continuar = 'n';

				sales(posicion);
				posicion++;
			}
			break;
	}
	return 0;
}

//FUNCTIONS & PROCEDURES
