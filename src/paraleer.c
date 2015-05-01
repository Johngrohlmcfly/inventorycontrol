#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000

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
} recepcion[SIZE], recepcionAux;



int main(){
	//struct articulos recepcionAux;
	FILE *ptrFile;
	ptrFile=fopen("papeleria.dat","rb");
	if(ptrFile!=NULL){
		fread(&recepcionAux,sizeof(recepcion),1,ptrFile);
		while(!feof(ptrFile)){
		printf("Nombre: %s\n#item: %d\nPiezas por caja: %d\nCantidad Recibida: %d\nExistencias: %d\nPrecio por caja $ %f\nPrecio unitario $ %f\n",recepcionAux.nombre, recepcionAux.numArticulo,recepcionAux.piezaPorCaja, recepcionAux.cantidadRecibida, recepcionAux.existencia, recepcionAux.precioporcaja, recepcionAux.precioUnitario);
		fread(&recepcionAux,sizeof(recepcion),1,ptrFile);
		}
		fclose(ptrFile);
	}
	else{
	printf("Error en la apertura del archivo");
	}
	return 0;
}