/*
 ============================================================================
 Name        : TP nº1.c
 Author      : mauro racioppi
 Division    : D
 Copyright   : Your copyright notice
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "UTN.h"

int main(void) {
setbuf(stdout, NULL);

int opcion;
int opcionAerolinaLatam;
int kilometros;
int entradaEnKilometros;
float precioAerolineas;
float precioLatam;
int calculosHechos;
int preciosIngresados;
float aerolineasDebito;
float aerolineasCredito;
float aerolineasBitcoint;
float aerolineasPrecioUnitario;
float latamDebito;
float latamCredito;
float latamBitcoint;
float latamPrecioUnitario;
float diferenciaLatamAerolinea;
int descuento;
int interes;

entradaEnKilometros = 0;
preciosIngresados = 0;
descuento = 10;
interes = 25;
calculosHechos=0;
precioAerolineas=0;
precioLatam=0;

do{
	UTN_getValidacionMaximoMinimo(&opcion,"\nIngrese un numero \n"
				" 1. Para ingresar los kilometros\n"
				" 2. Para ingresar los precios de vuelos ((Aerolíneas y Latam)\n"
				" 3. Para calcular los costos \n"
				" 4. Para mostrar los resultados \n"
				" 5. Para carga forzada \n"
				" 6. Para salir ", "\nERROR, Reingrese un numero valido\n"
					" 1. Para ingresar los kilometros\n"
					" 2. Para ingresar los precios de vuelos ((Aerolíneas y Latam)\n"
					" 3. Para calcular los costos \n"
					" 4. Para mostrar los resultados \n"
					" 5. Para carga forzada \n"
					" 6. Para salir", 1, 6);

	switch(opcion)
	{
		case 1:
			UTN_getValidacionMayorInt(&kilometros,"\nIngrese la cantidad de kilometros ",
					"\nError, reingrese la cantidad de kilometros (un numero mayor a 0)", 1);

			entradaEnKilometros = 1;
		break;

		case 2:
			do
			{
				UTN_getValidacionMaximoMinimo(&opcionAerolinaLatam,"\nIngrese un numero \n"
					" 1. Para ingresar el precio de Aerolíneas\n"
					" 2. Para ingresar el precio de Latam\n"
					" 3. para volver al menu ",
					"\nERROR, Reingrese un numero valido\n"
					" 1. Para ingresar el precio de Aerolíneas\n"
					" 2. Para ingresar el precio de Latam\n"
					" 3. para volver al menu ", 1, 3);
				switch(opcionAerolinaLatam)
				{
				case 1:
					UTN_getValidacionMayorfloat(&precioAerolineas,"\nIngrese el precio del vuelo en Aerolineas ",
							"\nError, reingrese el precio del vuelo en Aerolineas ", 1);
				break;
				case 2:
					UTN_getValidacionMayorfloat(&precioLatam,"\nIngrese el precio del vuelo en Latam ",
							"\nError, reingrese el precio del vuelo en Latam ", 1);
				break;
				}
			}
			while(opcionAerolinaLatam !=3);
			if(precioAerolineas>0 && precioLatam>0)
			{
				preciosIngresados = 1;
			}
		break;
		case 3:
			if(preciosIngresados==1 && entradaEnKilometros==1)
			{
				aerolineasDebito= get_descuento(precioAerolineas, descuento);
				aerolineasCredito= get_interes(precioAerolineas, interes);
				aerolineasBitcoint= get_PesosABitcoin(precioAerolineas);
				aerolineasPrecioUnitario= get_unitario(kilometros, precioAerolineas);
				latamDebito = get_descuento(precioLatam, descuento);
				latamCredito = get_interes(precioLatam, interes);
				latamBitcoint = get_PesosABitcoin(precioLatam);
				latamPrecioUnitario = get_unitario(kilometros, precioLatam);
				diferenciaLatamAerolinea = get_resta(precioLatam, precioAerolineas);
				if(diferenciaLatamAerolinea<0)
				{
					diferenciaLatamAerolinea= get_cambioSigno(diferenciaLatamAerolinea);
				}

				calculosHechos=1;
			}
			else
			{
				printf("Debe de ingresar primero los kilometros y los precios de cada aerolinea\n");
			}

		break;

		case 4:
			if(calculosHechos==1)
			{
				printf("\nKms ingresados: %d\n"
					"\nprecio latam: %.2f\n"
					"a) Precio con tarjeta de débito: %.2f\n"
					"b) Precio con tarjeta de crédito: %.2f\n"
					"c) Precio pagando con bitcoin: %.2f\n"
					"d) Precio unitario: %.2f\n"
					"\nprecio Aerolíneas: %.2f\n"
					"a) Precio con tarjeta de débito: %.2f\n"
					"b) Precio con tarjeta de crédito: %.2f\n"
					"c) Precio pagando con bitcoin: %.2f\n"
					"d) Precio unitario: %.2f\n"
					"\nLa diferencia de precio es: %.2f\n", kilometros, precioLatam, latamDebito, latamCredito, latamBitcoint,
					latamPrecioUnitario,precioAerolineas, aerolineasDebito, aerolineasCredito, aerolineasBitcoint,
					aerolineasPrecioUnitario, diferenciaLatamAerolinea);
			}
			else
			{
				printf("Error, antes debes de calcular los costos\n");
			}
		break;

		case 5:
			kilometros=7090;
			precioAerolineas=162965;
			precioLatam=159339;
			aerolineasDebito= get_descuento(precioAerolineas, descuento);
			aerolineasCredito= get_interes(precioAerolineas, interes);
			aerolineasBitcoint= get_PesosABitcoin(precioAerolineas);
			aerolineasPrecioUnitario= get_unitario(kilometros, precioAerolineas);
			latamDebito = get_descuento(precioLatam, descuento);
			latamCredito = get_interes(precioLatam, interes);
			latamBitcoint = get_PesosABitcoin(precioLatam);
			latamPrecioUnitario = get_unitario(kilometros, precioLatam);
			diferenciaLatamAerolinea = get_resta(precioLatam, precioAerolineas);
			if(diferenciaLatamAerolinea<0)
			{
				diferenciaLatamAerolinea= get_cambioSigno(diferenciaLatamAerolinea);
			}

			printf("Kms ingresados: %d\n"
					"\nprecio latam: %.2f\n"
					"a) Precio con tarjeta de débito: %.2f\n"
					"b) Precio con tarjeta de crédito: %.2f\n"
					"c) Precio pagando con bitcoin: %.2f\n"
					"d) Precio unitario: %.2f\n"
					"\nprecio Aerolíneas: %.2f\n"
					"a) Precio con tarjeta de débito: %.2f\n"
					"b) Precio con tarjeta de crédito: %.2f\n"
					"c) Precio pagando con bitcoin: %.2f\n"
					"d) Precio unitario: %.2f\n"
					"\nLa diferencia de precio es: %.2f\n", kilometros, precioLatam, latamDebito, latamCredito, latamBitcoint,
					latamPrecioUnitario,precioAerolineas, aerolineasDebito, aerolineasCredito, aerolineasBitcoint,
					aerolineasPrecioUnitario, diferenciaLatamAerolinea);
		break;
	}

}
while(opcion!=6);

return 0;

}
