#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pPasajero;
	int r;
	int i;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50],var7[50];

	r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",var1,var2,var3,var4,var5,var6,var7);

	for(i=0;i<1000;i++)
	{
		r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",var1,var2,var3,var4,var5,var6,var7);
		if(r!=7)
		{
			printf("no se cargo el pasajero");
			break;
		}
		else
		{
			switch(*(var6+1))
			{
				case 'c':
					strcpy(var6,"3");
				break;

				case 'x':
					strcpy(var6,"2");
				break;

				case 'i':
					strcpy(var6,"1");
				break;
			}
			pPasajero=Passenger_newParametros(var1,var2,var3,var4,var5,var6,var7);
		}

		printf("\nID:%d\tNom:%s\tApe:%s\tPre:%2.f\tCodVuel:%s\tTipPasa:%d\tEstadoVuel:%s"
						,pPasajero->id,pPasajero->nombre,pPasajero->apellido,pPasajero->precio,pPasajero->codigoVuelo,pPasajero->tipoPasajero,pPasajero->statusFlight);
		ll_add(pArrayListPassenger,pPasajero);
	}

	return 1;
}

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pPasajero;
	int r;
	int i;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50],var7[50];

	r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",var1,var2,var3,var4,var5,var6,var7);

	for(i=0;i<1000;i++)
	{
		r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",var1,var2,var3,var4,var5,var6,var7);
		if(r!=7)
		{
			printf("no se cargo el pasajero");
			break;
		}
		else
		{
			switch(*(var6+1))
			{
				case 'c':
					strcpy(var6,"3");
				break;

				case 'x':
					strcpy(var6,"2");
				break;

				case 'i':
					strcpy(var6,"1");
				break;
			}
			pPasajero=Passenger_newParametros(var1,var2,var3,var4,var5,var6,var7);
		}

		printf("ID:%d\tNombre:%s\tApellido:%s\tPrecio:%2.f\tCodigo de Vuelo:%s\tTipo de pasajero:%d\tEstado de vuelo:%s"
				,pPasajero->id,pPasajero->nombre,pPasajero->apellido,pPasajero->precio,pPasajero->codigoVuelo,pPasajero->tipoPasajero,pPasajero->statusFlight);
		ll_add(pArrayListPassenger,pPasajero);
	}

	return 1;
}
