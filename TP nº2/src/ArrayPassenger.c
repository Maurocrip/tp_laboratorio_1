/*
 * ArrayPassenger.c
 *
 *  Created on: 7 may. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "UTN.h"
#include "funcionesAuxiliares.h"


//FUNCIONES DEL ENUNCIADO
int initPassengers(Passenger* list, int len)
{
	int i;
	int devuelve;

	devuelve=-1;

	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty =1;
		}
		devuelve=0;
	}
	return devuelve;
}
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int i;
	int devuelve;

	devuelve=-1;

	if(list != NULL && len>0)
	{
		devuelve=0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty ==1)
			{
				strcpy(list[i].flycode, flycode);
				list[i].id = id;
				strcpy(list[i].lastName, lastName);
				strcpy(list[i].name, name);
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				list[i].isEmpty=0;
				list[i].statusFlight=statusFlight;
				break;
			}
		}
	}

	return devuelve;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int i;
	int devuelve;

	devuelve=-1;

	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				devuelve=i;
				break;
			}
		}
	}
	return devuelve;
}

int removePassenger(Passenger* list, int len, int id)
{
	int indice;
	int respuesta;

	respuesta=-1;
	if(list != NULL && len>0)
	{
		indice=findPassengerById(list, len, id);

		if(indice==-1)
		{
			respuesta=-1;
		}
		else
		{
			list[indice].isEmpty=1;
			respuesta=0;
		}
	}
	return respuesta;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int i;
	int j;
	int devuelve;
	Passenger guardado;

	devuelve=-1;

	if(list != NULL)
	{
		devuelve=0;
		for(i=0;i<len;i++)
		{
			for(j=i+1;j<len-1;j++)
			{
				if(list[i].isEmpty==0 && list[j].isEmpty==0)
				{
					if(order==0)
					{
						if(list[i].typePassenger<list[j].typePassenger)
						{
							guardado=list[j];
							list[j]=list[i];
							list[i]=guardado;
						}
						else
						{
							if(list[i].typePassenger==list[j].typePassenger)
							{
								if(strcmp(list[i].lastName,list[j].lastName)!=-1)
								{
									guardado=list[j];
									list[j]=list[i];
									list[i]=guardado;
								}
							}
						}
					}
					else
					{
						if(list[i].typePassenger>list[j].typePassenger)
						{
							guardado=list[j];
							list[j]=list[i];
							list[i]=guardado;
						}
						else
						{
							if(list[i].typePassenger==list[j].typePassenger)
							{
								if(strcmp(list[i].lastName,list[j].lastName)!=1)
								{
									guardado=list[j];
									list[j]=list[i];
									list[i]=guardado;
								}
							}
						}
					}
				}
			}
		}
	}

	return devuelve;
}

int printPassenger(Passenger* list, int length)
{
	int i;
	int respuesta;

	respuesta=-1;

	if(list != NULL)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==0)
			{
				printf("\nid: %d\nnombre: %s\napellido: %s\nprecio: %.2f\ncodigo del vuelo: %s\ntipo de pasajero: %d\nEstado del vuelo: %d\n",
						list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, list[i].typePassenger, list[i].statusFlight);
				respuesta=0;
			}
		}
	}
	return respuesta;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int i;
	int j;
	int devuelve;
	Passenger guardado;

	devuelve=-1;

	if(list != NULL)
	{
		devuelve=0;
		for(i=0;i<len;i++)
		{
			for(j=i+1;j<len-1;j++)
			{
				if(list[i].isEmpty==0 && list[j].isEmpty==0 && list[i].statusFlight==1 && list[j].statusFlight==1)
				{
					if(order==0)
					{
						if(list[i].flycode<=list[j].flycode)
						{
							guardado=list[j];
							list[j]=list[i];
							list[i]=guardado;
						}
					}
					else
					{
						if(list[i].flycode>=list[j].flycode)
						{
							guardado=list[j];
							list[j]=list[i];
							list[i]=guardado;
						}
					}
				}
			}
		}
	}

	return devuelve;
}

//FUNCIONES APARTE
void alta(Passenger persona, int id, Passenger* guardar, int tam)
{
	int validacion;
	persona.id=id;
	UTN_GetValor(persona.name, IDENTIFICACION, "ingrese su nombre: ", "ERROR, su nombre tiene mas de 51 digitos o contiene algun numero.\n"
			"Por favor ingrese su nombre nuevamente: ",0);
	UTN_GetValor(persona.lastName, IDENTIFICACION, "ingrese su apellido: ", "ERROR, su apellido tiene mas de 51 digitos o contiene algun numero.\n"
							"Por favor ingrese su apellido nuevamente: ",0);
	convertirPalabraAMinusculas(persona.lastName,IDENTIFICACION);
	UTN_getValidacionMayorfloat(&persona.price,"ingrese el precio del viaje: ", "ERROR, reingrese el precio del viaje(numero mayor a 0): ", 0);
	UTN_GetValor(persona.flycode, CODIGO, "ingrese su codigo: ", "ERROR, su codigo no puede tener mas de 10 cifras.\n"
							"Por favor ingrese su codigo nuevamente: ",1);
	convertirPalabraAMayusculas(persona.flycode,CODIGO);
	UTN_getValidacionMaximoMinimo(&persona.typePassenger, "ingrese el tipo de pasajero(1-Clase turista, 2-Comercial, 3-Primera calse): ",
			"ERROR, reingrese solo el numero correspondiente al tipo de pasajero(1-Clase turista, 2-Comercial, 3-Primera calse): ", 1,3);
	UTN_getValidacionMaximoMinimo(&persona.statusFlight, "ingrese 1 si su vuelo esta activo y 0 si no lo esta: ",
							"ERROR, reingrese solo el numero correspondiente al estado del vuelo(0-1): ", 0,1);
	validacion=addPassenger(guardar,tam,persona.id,persona.name,persona.lastName,persona.price,persona.typePassenger,persona.flycode,persona.statusFlight);
	if(validacion==0)
	{
		printf("\nSe ah guardado con exito, el ID de este pasajero es: %d\n",persona.id);
	}
	else
	{
		printf("\nNo se ah podido guardar al pasajero ya que no hay espacio disponible\n");
	}
}

void modificacion(Passenger* lista, int tam)
{
	int idBuscar;
	int validar;
	int opcion;

	UTN_getValidacionMayorInt(&idBuscar, "ingrese el ID del pasajero que desea modificar: ", "ERROR, ingrese un ID valido(numero mayor a 0): ",1);
	validar=findPassengerById(lista,tam,idBuscar);
	if(validar!=-1)
	{
		do
		{
			UTN_getValidacionMaximoMinimo(&opcion,"\nIngrese un numero \n"
					" 1. Modifica nombre\n"
					" 2. Modifica apellido\n"
					" 3. Modifica precio\n"
					" 4. Modifica tipo de pasajero\n"
					" 5. Modificar Código de vuelo\n"
					" 6. Modificar estado de vuelo\n"
					" 7. SALIR ", "\nERROR, Reingrese un numero valido(1-7)\n"
						" 1. Modifica nombre\n"
						" 2. Modifica apellido\n"
						" 3. Modifica precio\n"
						" 4. Modifica tipo de pasajero\n"
						" 5. Modificar Código de vuelo\n"
						" 6. Modificar estado de vuelo\n"
						" 7. SALIR ", 1, 7);
			switch(opcion)
			{
				case 1:
					modificarNombre(lista,tam,validar);
				break;

				case 2:
					modificarApellido(lista,tam,validar);
				break;

				case 3:
					modificarPrecio(lista,tam,validar);
				break;

				case 4:
					modificarTipoPasajero(lista,tam,validar);
				break;

				case 5:
					modificarCodigo(lista,tam,validar);
				break;
				case 6:
					modificarEstadoDeVuelo(lista,tam,validar);
				break;
			}
		}while(opcion!=7);
	}
	else
	{
		printf("\nERROR, el ID %d no se encuentra en la lista\n", idBuscar);
	}
}

void modificarNombre(Passenger* guardar, int tam, int indice)
{
	int validarChar;
	validarChar=UTN_GetValor(guardar[indice].name, IDENTIFICACION, "ingrese su nombre: ", "ERROR, su nombre tiene mas de 51 digitos o contiene algun numero.\n"
									"Por favor ingrese su nombre nuevamente: ",0);
	if(validarChar==0)
	{
		printf("\nel nombre se ah cambiado por %s\n", guardar[indice].name);
	}
	else
	{
		printf("\nERROR, no se ah podido cambiar el nombre\n");
	}
}

void modificarApellido(Passenger* guardar, int tam, int indice)
{
	int validarChar;
	validarChar=UTN_GetValor(guardar[indice].lastName, IDENTIFICACION, "ingrese su apellido: ",
			"ERROR, su apellido tiene mas de 51 digitos o contiene algun numero.\nPor favor ingrese su apellido nuevamente: ",0);
	convertirPalabraAMinusculas(guardar[indice].lastName,IDENTIFICACION);
	if(validarChar==0)
	{
		printf("\nel apellido se ah cambiado por %s\n", guardar[indice].lastName);
	}
	else
	{
		printf("\nERROR, no se ah podido cambiar el apellido\n");
	}
}

void modificarPrecio(Passenger* guardar, int tam, int indice)
{
	UTN_getValidacionMayorfloat(&guardar[indice].price,"ingrese el nuevo precio del viaje: ",
			"ERROR, reingrese el nuevo precio del viaje(numero mayor a 0): ", 0);
	printf("\nel precio se ah cambiado por %f\n", guardar[indice].price);
}

void modificarTipoPasajero(Passenger* guardar, int tam, int indice)
{
	UTN_getValidacionMaximoMinimo(&guardar[indice].typePassenger, "ingrese el nuevo tipo de pasajero(1-Clase turista, 2-Comercial, 3-Primera calse): ",
				"ERROR, reingrese solo el numero correspondiente al tipo de pasajero(1-Clase turista, 2-Comercial, 3-Primera calse): ", 1,3);
	printf("\nel tipo de pasajero se ah cambiado\n");
}

void modificarCodigo(Passenger* guardar, int tam, int indice)
{
	UTN_GetValor(guardar[indice].flycode, CODIGO, "ingrese su nuevo codigo: ",
			"ERROR, su nuevo codigo no puede tener mas de 10 cifras.\nPor favor ingrese su nuevo codigo nuevamente: ",1);
	convertirPalabraAMayusculas(guardar[indice].flycode,CODIGO);
	printf("\nel codigo se ah cambiado a %s\n", guardar[indice].flycode);
}

void modificarEstadoDeVuelo(Passenger* guardar, int tam, int indice)
{
	UTN_getValidacionMaximoMinimo(&guardar[indice].statusFlight, "ingrese 1 si su vuelo esta activo y 0 si no lo esta: ",
					"ERROR, reingrese solo el numero correspondiente al estado del vuelo(0-1): ", 0,1);
	printf("\nel estado del vuelo se ah cambiado a %d\n", guardar[indice].statusFlight);
}


void baja(Passenger* lista, int tam)
{
	int idBuscar;
	int validar;

	UTN_getValidacionMayorInt(&idBuscar, "ingrese el ID del pasajero que desea dar de baja: ", "ERROR, ingrese un ID valido(numero mayor a 0): ",1);
	validar=findPassengerById(lista,tam,idBuscar);
	if(validar!=-1)
	{
		removePassenger(lista,tam,validar);
		printf("\nEl ID %d se ah eliminado correctamente\n", idBuscar);
	}
	else
	{
		printf("\nERROR, el ID %d no se encuentra en la lista\n", idBuscar);
	}
}

void informar(Passenger* lista, int tam)
{
	int opcion;
	float precioTotal;
	int pasajerostotal;
	float promedioPrecios;
	int cantidadPasajerosMayorPromedio;
	do
	{
		UTN_getValidacionMaximoMinimo(&opcion,"\nIngrese un numero \n"
				" 1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n"
				" 2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
				" 3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n"
				" 4. SALIR\n", "\nERROR, Reingrese un numero valido(1-4)\n"
					" 1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n"
					" 2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
					" 3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n"
					" 4. SALIR\n", 1, 4);
		switch(opcion)
		{
			case 1:
				sortPassengers(lista,tam,0);
				printPassenger(lista,tam);
			break;

			case 2:
				precioTotal=totalPrecioPasajeros(lista,tam);
				pasajerostotal=cantidadPasajeros(lista,tam);
				promedioPrecios=promedio(precioTotal,pasajerostotal);
				cantidadPasajerosMayorPromedio=cantidadPasajerosSuperanPrecioPromedio(lista,tam,promedioPrecios);
				printf("\nEl precio total de los pasajes es de: %.2f\n"
						"El precio promedio de los pasajes es de: %.2f\n"
						"la cantidad de pasajeros que superan el precio promedio de los pasaje es de: %d\n",precioTotal, promedioPrecios,cantidadPasajerosMayorPromedio);
			break;

			case 3:
				sortPassengersByCode(lista,tam,1);
				printPassengerPorEstadoVuelo(lista,tam);
			break;
		}
	}while(opcion!=4);
}

int printPassengerPorEstadoVuelo(Passenger* list, int length)
{
	int i;
	int respuesta;

	respuesta=-1;

	if(list != NULL)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==0 && list[i].statusFlight==1)
			{
				printf("\nid: %d\nnombre: %s\napellido: %s\nprecio: %.2f\ncodigo del vuelo: %s\ntipo de pasajero: %d\nEstado del vuelo: %d\n",
						list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, list[i].typePassenger, list[i].statusFlight);
				respuesta=0;
			}
		}
	}
	return respuesta;
}

float totalPrecioPasajeros(Passenger* list, int length)
{
	float precioTotal;
	int i;

	precioTotal=0;

	for(i=0;i<length;i++)
	{
		if(list[i].isEmpty==0)
		{
			precioTotal=precioTotal+ list[i].price;
		}
	}

	return precioTotal;
}

int cantidadPasajeros(Passenger* list, int length)
{
	int cantidad;
	int i;

	cantidad=0;

	for(i=0;i<length;i++)
	{
		if(list[i].isEmpty==0)
		{
			cantidad++;
		}
	}

	return cantidad;
}

int cantidadPasajerosSuperanPrecioPromedio(Passenger* list, int length, float precioPromedio)
{
	int cantidad;
	int i;

	cantidad=0;

	for(i=0;i<length;i++)
	{
		if(list[i].price>precioPromedio && list[i].isEmpty==0)
		{
			cantidad++;
		}
	}

	return cantidad;
}

void cargaForzada(Passenger* list, int length)
{
	//addPassenger(list,length,1245, "psajero uno","FULANITO",20000,1,"CODIGO1",0);

	strcpy(list[0].flycode, "CODIGO1");
	list[0].id = 1245;
	strcpy(list[0].lastName, "FULANITO");
	strcpy(list[0].name, "psajero uno");
	list[0].price = 20000;
	list[0].typePassenger = 1;
	list[0].isEmpty=0;
	list[0].statusFlight=0;

	//addPassenger(list,length,6789, "psajero dos","MENGANA",50000,1,"CODIGO2",1);

	strcpy(list[1].flycode, "CODIGO2");
	list[1].id = 6789;
	strcpy(list[1].lastName, "MENGANA");
	strcpy(list[1].name, "psajero dos");
	list[1].price = 50000;
	list[1].typePassenger = 1;
	list[1].isEmpty=0;
	list[1].statusFlight=1;

	informar(list,length);
}
