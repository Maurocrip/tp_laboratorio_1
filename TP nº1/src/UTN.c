/*
 * UTN.c
 *
 *  Created on: 8 abr. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>

int UTN_getValidacionMaximoMinimo(int* resultado, char* mensaje,char* mensajeError, int minimo, int maximo)
{
	printf(mensaje);
	scanf("%d", resultado);
	while(*resultado<minimo || *resultado>maximo)
	{
		printf(mensajeError);
		scanf("%d", resultado);
	}
	return 0;
}

int UTN_getValidacionMayorInt(int* resultado, char* mensaje,char* mensajeError, int numero)
{
	printf(mensaje);
	scanf("%d", resultado);
	while(*resultado<numero)
	{
		printf(mensajeError);
		scanf("%d", resultado);
	}
	return 0;
}

int UTN_getValidacionMayorfloat(float* resultado, char* mensaje,char* mensajeError, int numero)
{
	printf(mensaje);
	scanf("%f", resultado);
	while(*resultado<numero)
	{
		printf(mensajeError);
		scanf("%f", resultado);
	}
	return 0;
}



