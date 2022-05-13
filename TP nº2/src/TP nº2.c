/*
 ============================================================================
 Name        : ejercicio.c
 Author      : mauro racioppi
 DIV	     : D
 Description : Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
 no puede tener más de 2000 pasajeros.

 El sistema deberá tener el siguiente menú de opciones:
 1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el número de Id. El resto de los campos se le pedirá al usuario.
 2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido o Precio o Tipo de pasajero o Código de vuelo
 3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
 4. INFORMAR:
 	 1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
 	 2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
 	 3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’

 1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
 Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la carga de algún pasajero.

 2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "UTN.h"
#define CANTIDAD 2000
#define CARGA 2

int main(void)
{
	setbuf(stdout, NULL);
	Passenger registro[CANTIDAD];
	Passenger forzado[CARGA];
	Passenger pj;
	int respuesta;
	int id;
	int validacion;
	id=0;
	validacion=0;

	//inicializa todos los isEmpty del array en LIBRES(1).
	initPassengers(registro, CANTIDAD);

	//MENU
	do
	{
		UTN_getValidacionMaximoMinimo(&respuesta,"\nIngrese un numero \n"
				" 1. ALTAS\n"
				" 2. MODIFICAR\n"
				" 3. BAJA\n"
				" 4. INFORMAR\n"
				" 5. CARGA FORZADA\n"
				" 6. SALIR ", "\nERROR, Reingrese un numero valido(1-6)\n"
					" 1. ALTAS\n"
					" 2. MODIFICAR\n"
					" 3. BAJA\n"
					" 4. INFORMAR\n"
					" 5. CARGA FORZADA\n"
					" 6. SALIR ", 1, 6);
		validacion=cantidadPasajeros(registro,CANTIDAD);

		switch(respuesta)
		{
			case 1:
				//INGRESO DE PASAJEROSç
				id++;
				alta(pj,id,registro,CANTIDAD);
			break;

			case 2:
				//MODIFICA UN PASAJERO
				if(validacion!=0)
				{
					modificacion(registro,CANTIDAD);
				}
				else
				{
					printf("\nIngrese un pasajero antes\n");
				}
			break;

			case 3:
				//ELIMINA UN PASAJERO
				if(validacion!=0)
				{
					baja(registro,CANTIDAD);
				}
				else
				{
					printf("\nIngrese un pasajero antes\n");
				}
			break;

			case 4:
				//INFORMA UN LISTADO
				if(validacion!=0)
				{
					informar(registro,CANTIDAD);
				}
				else
				{
					printf("\nIngrese un pasajero antes\n");
				}
			break;

			case 5:
				//HARCODEA LOS DATOS DEL PASAJERO
				cargaForzada(forzado,CARGA);
			break;
		}
	}while(respuesta!=6);

	return 0;
}
