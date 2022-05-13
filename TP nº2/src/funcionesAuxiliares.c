/*
 * funcionesAuxiliares.c
 *
 *  Created on: 12 may. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convertirPalabraAMayusculas(char comprobar[], int tam)
{
	int i;

	if(comprobar != NULL)
	{
		for(i=0;i<tam;i++)
		{
			comprobar[i]=toupper(comprobar[i]);
		}
	}
}

void convertirPalabraAMinusculas(char comprobar[], int tam)
{
	int i;

	if(comprobar != NULL)
	{
		for(i=0;i<tam;i++)
		{
			comprobar[i]=tolower(comprobar[i]);
		}
	}
}

float promedio(float numeroTotal, int cantidadNumero)
{
	float resultado;

	resultado= numeroTotal/cantidadNumero;
	return resultado;
}
