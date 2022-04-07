/*
 ============================================================================
 Name        : TP nº1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
setbuf(stdout, NULL);

int respuesta;

do{
	printf("Ingrese un numeron n/"
			" 1. Para ingresar los kilometros/n"
			" 2. Para ingresar los precios de vuelos ((Aerolíneas y Latam)/n"
			" 3. Para calcular los costos /n"
			"4. Para mostrar los resultados /n "
			"5. Para carga forzada /n"
			"6. Para salir ");
	scanf("%d", &respuesta);
	while(respuesta<1 && respuesta>6)
	{
		printf("ERROR, Reingrese un numero valido/n"
				" 1. Para ingresar los kilometros/n"
				" 2. Para ingresar los precios de vuelos ((Aerolíneas y Latam)/n"
				" 3. Para calcular los costos /n"
				"4. Para mostrar los resultados /n "
				"5. Para carga forzada /n"
				"6. Para salir ");
		scanf("%d", &respuesta);
	}

}
while(respuesta==6);



return 0;

}
