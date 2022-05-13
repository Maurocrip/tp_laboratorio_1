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

void convertirPalabraAMayusculas(char comprobar[], int indice)
{
	int i;

	if(comprobar != NULL)
	{
		for(i=0;i<indice;i++)
		{
			comprobar[i]=toupper(comprobar[i]);
		}
	}
}

void convertirPalabraAMinusculas(char comprobar[], int indice)
{
	int i;

	if(comprobar != NULL)
	{
		for(i=0;i<indice;i++)
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
