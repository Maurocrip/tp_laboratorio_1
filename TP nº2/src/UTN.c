/*
 * UTN.c
 *
 *  Created on: 8 may. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int UTN_getValidacionMaximoMinimo(int* resultado, char* mensaje,char* mensajeError, int minimo, int maximo)
{
	printf(mensaje);
	fflush(stdin);
	scanf("%d", resultado);

	while(*resultado<minimo || *resultado>maximo)
	{
		printf(mensajeError);
		fflush(stdin);
		scanf("%d", resultado);
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
	fflush(stdin);
	scanf("%f", resultado);
	while(*resultado<numero)
	{
		printf(mensajeError);
		fflush(stdin);
		scanf("%f", resultado);
	}
	return 0;
}

int UTN_GetValor(char array[], int tam, char* mensaje, char* mensajeError, int conNumero)
{
	int i;
	int devuelve;
	int comprobacion;
	devuelve=-1;
	if(array!=NULL)
	{
		devuelve=0;

		printf(mensaje);
		fflush(stdin);
		gets(array);

		while(strlen(array)>tam)
		{
			printf(mensajeError);
			gets(array);
			fflush(stdin);

		}
		if(conNumero==0)
		{
			do
			{
				for(i=0;i<tam;i++)
				{
					comprobacion= isdigit(array[i]);
					if (comprobacion !=0)
					{
						printf(mensajeError);
						gets(array);
						fflush(stdin);
						break;
					}
				}
			}while(comprobacion!=0);
		}
	}
	return devuelve;
}
