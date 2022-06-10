/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"


Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* statusFlightStr)
{
	Passenger* pAux= (Passenger*) malloc(sizeof(Passenger));

	pAux->id=atoi(idStr);
	strcpy(pAux->nombre, nombreStr);
	strcpy(pAux->apellido, apellidoStr);
	pAux->precio=atof(precioStr);
	pAux->tipoPasajero=atoi(tipoPasajeroStr);
	strcpy(pAux->codigoVuelo, codigoVueloStr);
	pAux->isEmpty=1;
	strcpy(pAux->statusFlight, statusFlightStr);

	return pAux;
}
