#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000

void addproducts(int a);
void downproducts();
void sales(int a);

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
} recepcion[SIZE], ventas[SIZE];

//struct para baja de articulos
struct bajaart {
	short flag;

	char nombre[100];

	int numArticulo;

	struct fecha fbaja;
} bajas[SIZE];

//struct para registro de ventas
struct ventas {
	short flag;

	char nombre[100];

	int cantidad;
	int numArticulo;

	float precio;
	float monto;
	float descuento;
	float iva;
	float subtotal;
	float total;

	struct fecha fventa;
} movimientos[SIZE];
