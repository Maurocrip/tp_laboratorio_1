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
	fflush(stdin);
	while(*resultado<minimo || *resultado>maximo)
	{
		printf(mensajeError);
		scanf("%d", resultado);
		fflush(stdin);
	}
	return 0;
}

int UTN_getValidacionMayorInt(int* resultado, char* mensaje,char* mensajeError, int numero)
{
	printf(mensaje);
	scanf("%d", resultado);
	fflush(stdin);
	while(*resultado<numero)
	{
		printf(mensajeError);
		scanf("%d", resultado);
		fflush(stdin);
	}
	return 0;
}

int UTN_getValidacionMayorfloat(float* resultado, char* mensaje,char* mensajeError, int numero)
{
	printf(mensaje);
	scanf("%f", resultado);
	fflush(stdin);
	while(*resultado<numero)
	{
		printf(mensajeError);
		scanf("%f", resultado);
		fflush(stdin);
	}
	return 0;
}



