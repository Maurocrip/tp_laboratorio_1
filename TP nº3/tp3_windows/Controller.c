#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"
#include "UTN.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int cantidad;
	int i;
	Passenger* pPasajero= (Passenger*) malloc(sizeof(Passenger));

	pArchivo=fopen(path,"r");
	if(pArchivo==NULL)
	{
		printf("\nEl archivo no se pudo abrir\n");
		exit (1);
	}

	cantidad=ll_len(pArrayListPassenger);
	if(cantidad>0)
	{
		printf("\nSe les ah modificado el ID a Los pasajeros cargados anteriormente");
		for(i=0;i<cantidad;i++)
		{
			pPasajero=ll_get(pArrayListPassenger,i);
			pPasajero->id=pPasajero->id+1000;
			printf("\n%d,%s,%s,%f,%s,%d,%s \n",pPasajero->id,pPasajero->nombre,pPasajero->apellido,pPasajero->precio,pPasajero->codigoVuelo,pPasajero->tipoPasajero,pPasajero->statusFlight);
		}
	}

	parser_PassengerFromText(pArchivo,pArrayListPassenger);
	fclose(pArchivo);
    return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int cantidad;
	int i;
	Passenger* pPasajero= (Passenger*) malloc(sizeof(Passenger));

	pArchivo=fopen(path,"rb");
	if(pArchivo==NULL)
	{
		printf("\nEl archivo no se pudo abrir\n");
		exit (1);
	}

	cantidad=ll_len(pArrayListPassenger);
	if(cantidad>0)
	{
		printf("\nSe les ah modificado el ID a Los pasajeros cargados anteriormente\n");
		for(i=0;i<cantidad;i++)
		{
			pPasajero=ll_get(pArrayListPassenger,i);
			pPasajero->id=pPasajero->id+1000;
			printf("\n%d,%s,%s,%f,%s,%d,%s \n",pPasajero->id,pPasajero->nombre,pPasajero->apellido,pPasajero->precio,pPasajero->codigoVuelo,pPasajero->tipoPasajero,pPasajero->statusFlight);
		}
	}

	parser_PassengerFromBinary(pArchivo,pArrayListPassenger);
	fclose(pArchivo);
	return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int devuelve;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];
	int var7;
	Passenger* pPasajero= (Passenger*) malloc(sizeof(Passenger));

	devuelve=0;

	if(pArrayListPassenger!=NULL)
	{
		devuelve=1;
		pPasajero->id=ll_len(pArrayListPassenger);
		if(pPasajero->id==0)
		{
			strcpy(var1,"1");
		}
		else
		{
			pPasajero->id++;
			itoa(pPasajero->id,var1,10);
		}

		UTN_GetValor(var2,CARACTERES,"Ingrese su nombre: ",
				"\nERROR, su nombre no puede contener numeros o excederse de los 50 caracteres\nIngrese su nombre: ",0);
		UTN_GetValor(var3,CARACTERES,"Ingrese su apellido: ",
					"\nERROR, su apellido no puede contener numeros o excederse de los 50 caracteres\nIngrese su apellido: ",0);
		UTN_getValidacionMayorfloat(var4,"Ingrese el precio del vuelo: ",
				"\nERROR, el precio del vuelo no puede contener letras o ser menor a 0\nIngrese el precio del vuelo: ",0);
		UTN_GetValor(var5,7,"Ingrese su codigo de vuelo: ",
					"\nERROR, su codigo de vuelo no excederse de los 7 caracteres\nIngrese codigo de vuelo: ",1);
		UTN_getValidacionMaximoMinimo(&pPasajero->tipoPasajero,"Ingrese el tipo de pasajero(1=FirstClass 2=ExecutiveClass 3=EconomyClass): ",
				"\nERROR, Reingrese un numero valido(1-3)\nIngrese el tipo de pasajero(1=FirstClass 2=ExecutiveClass 3=EconomyClass): ", 1, 3);
		itoa(pPasajero->tipoPasajero,var6,50);
		UTN_getValidacionMaximoMinimo(&var7,"Ingrese el estado de vuelo(1=Aterrizado 2=En horario 3=Demorado): ",
				"\nERROR, Reingrese solo un numero valido(1-3)\nIngrese el estado de vuelo(1=Aterrizado 2=En horario 3=Demorado): ", 1, 3);
		switch(var7)
		{
			case 1:
				strcpy(pPasajero->statusFlight,"Aterrizado");
			break;

			case 2:
				strcpy(pPasajero->statusFlight,"En horario");
			break;

			case 3:
				strcpy(pPasajero->statusFlight,"Demorado");
			break;
		}

		pPasajero=Passenger_newParametros(var1,var2,var3,var4,var5,var6,pPasajero->statusFlight);
		printf("\n%d,%s,%s,%f,%s,%d,%s",pPasajero->id,pPasajero->nombre,pPasajero->apellido,pPasajero->precio,pPasajero->codigoVuelo,pPasajero->tipoPasajero,pPasajero->statusFlight);
		ll_add(pArrayListPassenger,pPasajero);
	}

    return devuelve;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{

    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

