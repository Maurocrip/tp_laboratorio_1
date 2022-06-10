/*
 * UTN.c
 *
 *  Created on: 6 jun. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"

int UTN_getValidacionMaximoMinimo(int* resultado, char* mensaje,char* mensajeError, int minimo, int maximo)
{
	char array[100];
	int devuelve;

	printf(mensaje);
	fflush(stdin);
	gets(array);

	devuelve=chearLetraint(array,100);

	while(devuelve!=0)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
	}

	*resultado=atoi(array);

	while(*resultado<minimo || *resultado>maximo)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
		while(devuelve!=0)
		{
			printf(mensajeError);
			fflush(stdin);
			gets(array);
			devuelve=chearLetraint(array,100);
		}
		*resultado=atoi(array);
	}
	return 0;
}

int chearLetraint(char* array, int tam)
{
	int resultado;
	int i;

	resultado=-1;
	if(array!=NULL)
	{
		for(i=0;*(array+i)!='\0';i++)
		{
			resultado=isalpha(*(array+i));
			if(resultado!=0)
			{
				break;
			}
		}
	}
	return resultado;
}

int UTN_GetValor(char* array, int tam, char* mensaje, char* mensajeError, int conNumero)
{
	int i;
	int devuelve;
	int comprobacion;
	devuelve=-1;
	if(array!=NULL && tam>0)
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
				for(i=0;*(array+i)!='\0';i++)
				{
					comprobacion= isdigit(*(array+i));
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


int UTN_getValidacionMayorfloat(char* resultado, char* mensaje,char* mensajeError, int numero)
{
	char array[100];
	int devuelve;
	int integral;

	printf(mensaje);
	fflush(stdin);
	gets(array);

	devuelve=chearLetraint(array,100);

	while(devuelve!=0)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
	}

	integral=atof(array);

	while(integral<numero)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
		while(devuelve!=0)
		{
			printf(mensajeError);
			fflush(stdin);
			gets(array);
			devuelve=chearLetraint(array,100);
		}
		integral=atof(array);
	}
	strcpy(resultado, array);
	return 0;
}

int UTN_getValidacionMayorInt(int* resultado, char* mensaje,char* mensajeError, int numero)
{
	char array[100];
	int devuelve;

	printf(mensaje);
	fflush(stdin);
	gets(array);

	devuelve=chearLetraint(array,100);

	while(devuelve!=0)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
	}

	*resultado=atoi(array);

	while(*resultado<numero)
	{
		printf(mensajeError);
		fflush(stdin);
		gets(array);
		devuelve=chearLetraint(array,100);
		while(devuelve!=0)
		{
			printf(mensajeError);
			fflush(stdin);
			gets(array);
			devuelve=chearLetraint(array,100);
		}
		*resultado=atoi(array);
	}
	return 0;
}

void convertirPalabraAMayusculas(char* comprobar, int tam)
{
	int i;

	if(comprobar != NULL)
	{
		for(i=0;i<tam;i++)
		{
			*(comprobar+i)=toupper(*(comprobar+i));
		}
	}
}
