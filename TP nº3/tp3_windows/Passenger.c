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
#include "UTN.h"


Passenger* Passenger_new()
{
	Passenger* pAux= (Passenger*) malloc(sizeof(Passenger));
	if(pAux==NULL)
	{
		printf("\nNo se pudo crear un nuevo pasajero\n");
		exit(1);
	}
	return pAux;
}

int Passenger_delete(Passenger* this )
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		this->isEmpty=0;
		printf("\nEl pasajero:\n\nID:%d \nNombre:%s \nApellido:%s \nPrecio:%f \nCodigo de Vuelo:%s \nTipo de pasajero:%d \nEstado de vuelo:%s\n\nHa sido eliminado",
				this->id,this->nombre,this->apellido,this->precio,this->codigoVuelo,this->tipoPasajero,this->statusFlight);
	}
	return devuelve;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* statusFlightStr)
{
	Passenger* pAux=Passenger_new();


	Passenger_setId(pAux,atoi(idStr));
	Passenger_setNombre(pAux,nombreStr);
	Passenger_setApellido(pAux,apellidoStr);
	Passenger_setPrecio(pAux,atof(precioStr));
	Passenger_setTipoPasajero(pAux,atoi(tipoPasajeroStr));
	Passenger_setCodigoVuelo(pAux,codigoVueloStr);
	pAux->isEmpty=1;
	Passenger_setStatusFlight(pAux, statusFlightStr);

	return pAux;
}

//---------------------------------------------------------FUNCIONES GET AND SET----------------------------------------------------------------------------------

int Passenger_setId(Passenger* this,int id)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		this->id=id;
	}
	return devuelve;
}

int Passenger_getId(Passenger* this,int* id)
{
	int devuelve=0;
	if(this!=NULL && id!=NULL)
	{
		devuelve=1;
		*id=this->id;
	}
	return devuelve;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		strcpy(this->nombre,nombre);
	}
	return devuelve;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int devuelve=0;
	if(this!=NULL && nombre!=NULL)
	{
		devuelve=1;
		strcpy(nombre,this->nombre);
	}
	return devuelve;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		strcpy(this->apellido,apellido);
	}
	return devuelve;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int devuelve=0;
	if(this!=NULL && apellido!=NULL)
	{
		devuelve=1;
		apellido=this->apellido;
	}
	return devuelve;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		strcpy(this->codigoVuelo,codigoVuelo);
	}
	return devuelve;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int devuelve=0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		devuelve=1;
		codigoVuelo=this->codigoVuelo;
	}
	return devuelve;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		this->tipoPasajero=tipoPasajero;
	}
	return devuelve;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int devuelve=0;
	if(this!=NULL && tipoPasajero!=NULL)
	{
		devuelve=1;
		*tipoPasajero=this->tipoPasajero;
	}
	return devuelve;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		this->precio=precio;
	}
	return devuelve;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int devuelve=0;
	if(this!=NULL && precio!=NULL)
	{
		devuelve=1;
		*precio=this->precio;
	}
	return devuelve;
}

int Passenger_setStatusFlight(Passenger* this,char* statusFlight)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		strcpy(this->statusFlight,statusFlight);
	}
	return devuelve;

}

int Passenger_getStatusFlight(Passenger* this,char* statusFlight)
{
	int devuelve=0;
	if(this!=NULL && statusFlight!=NULL)
	{
		devuelve=1;
		statusFlight=this->codigoVuelo;
	}
	return devuelve;
}

//--------------------------------------------------------------------FIN FUNCIONES GET AND SET-------------------------------------------------------------------


//------------------------------------------------------------FUNCIONES PARA EL MENU DE MODIFICACIONES------------------------------------------------------------

int modificarNombre(Passenger* pasajeroModificar)
{
	int devuelve;
	devuelve=0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_GetValor(pasajeroModificar->nombre,CARACTERES,"Ingrese el nuevo nombre: ",
			"\nERROR, el nuevo nombre no puede contener numeros o excederse de los 50 caracteres\nIngrese el nuevo nombre: ",0);
		printf("\nEl nuevo nombre es: %s\n",pasajeroModificar->nombre);
	}
	return devuelve;
}

int modificarApellido(Passenger* pasajeroModificar)
{
	int devuelve;
	devuelve=0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_GetValor(pasajeroModificar->apellido,CARACTERES,"Ingrese el nuevo apellido: ",
			"\nERROR, el nuevo apellido no puede contener numeros o excederse de los 50 caracteres\nIngrese el nuevo apellido: ",0);
		printf("\nEl nuevo apellido es: %s\n",pasajeroModificar->apellido);
	}
	return devuelve;
}

int modificarPrecio(Passenger* pasajeroModificar)
{
	int devuelve;
	char precio[50];
	devuelve=0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_getValidacionMayorfloat(precio,"Ingrese el nuevo precio del vuelo: ",
			"\nERROR, el nuevo precio del vuelo no puede contener letras o ser menor a 0\nIngrese el nuevo precio del vuelo: ",0);
		pasajeroModificar->precio=atof(precio);
		printf("\nEl nuevo precio es: %f\n",pasajeroModificar->precio);
	}
	return devuelve;
}

int modificarCodigoVuelo(Passenger* pasajeroModificar)
{
	int devuelve;
	devuelve=0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_GetValor(pasajeroModificar->codigoVuelo,7,"Ingrese el nuevo Codigo de Vuelo: ",
			"\nERROR, el nuevo Codigo de Vuelo no excederse de los 7 caracteres\nIngrese el nuevo Codigo de Vuelo: ",1);
		convertirPalabraAMayusculas(pasajeroModificar->codigoVuelo,7);
		printf("\nEl nuevo codigo de vuelo es: %s\n",pasajeroModificar->codigoVuelo);
	}
	return devuelve;
}

int modificarTipoPasajero(Passenger* pasajeroModificar)
{
	int devuelve;
	devuelve=0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_getValidacionMaximoMinimo(&pasajeroModificar->tipoPasajero,"Ingrese el nuevo tipo de pasajero(1=FirstClass 2=ExecutiveClass 3=EconomyClass): ",
			"\nERROR, Reingrese un numero valido(1-3)\nIngrese el nuevo tipo de pasajero(1=FirstClass 2=ExecutiveClass 3=EconomyClass): ", 1, 3);
		switch(pasajeroModificar->tipoPasajero)
		{
			case 1:
				printf("\nEl nuevo tipo de pasajero es: FirstClass\n");
			break;

			case 2:
				printf("\nEl nuevo tipo de pasajero es: ExecutiveClass\n");
			break;

			case 3:
				printf("\nEl nuevo tipo de pasajero es: EconomyClass\n");
			break;
		}
	}
	return devuelve;
}

int modificarestadoVuelo(Passenger* pasajeroModificar)
{
	int estado;
	int devuelve;
	devuelve=0;

	if(pasajeroModificar!=NULL)
	{
		devuelve=1;
		UTN_getValidacionMaximoMinimo(&estado,"Ingrese el nuevo estado de vuelo(1=Aterrizado 2=En horario 3=Demorado): ",
			"\nERROR, Reingrese solo un numero valido(1-3)\nIngrese el estado de vuelo(1=Aterrizado 2=En horario 3=Demorado): ", 1, 3);
		switch(estado)
		{
			case 1:
				strcpy(pasajeroModificar->statusFlight,"Aterrizado");
				printf("\nEl nuevo estado de vuelo es: Aterrizado\n");
			break;

			case 2:
				strcpy(pasajeroModificar->statusFlight,"En horario");
				printf("\nEl nuevo estado de vuelo es: En horario\n");
			break;

			case 3:
				strcpy(pasajeroModificar->statusFlight,"Demorado");
				printf("\nEl nuevo estado de vuelo es: Demorado\n");
			break;
		}
	}
	return devuelve;
}
//--------------------------------------------------------------------FIN FUNCIONES PARA EL MENU DE MODIFICACIONES------------------------------------------------

int mostrarPasajero(Passenger* pasajero)
{
	int devuelve;
	devuelve=0;
	if(pasajero!=NULL)
	{
		devuelve=1;
		printf("\nID:%d Nombre:%s Apellido:%s Precio:%2.f Codigo de Vuelo:%s Tipo de pasajero:%d Estado de vuelo:%s"
			,pasajero->id,pasajero->nombre,pasajero->apellido,pasajero->precio,pasajero->codigoVuelo,pasajero->tipoPasajero,pasajero->statusFlight);
	}
	return devuelve;
}

int comparaionID(Passenger* pasajero1,Passenger* pasajero2)
{
	int devuelve;
	devuelve=0;
	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		devuelve=1;
		Passenger* comodin= (Passenger*) malloc(sizeof(Passenger));
		if(pasajero1->id>pasajero2->id)
		{
			cambioPasajero(comodin,pasajero2);
			cambioPasajero(pasajero2,pasajero1);
			cambioPasajero(pasajero1,comodin);
		}
		free(comodin);
	}
	return devuelve;
}

int cambioPasajero(Passenger* pasajero1,Passenger* pasajero2)
{
	int devuelve;
	devuelve=0;
	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		Passenger_setId(pasajero1,pasajero2->id);
		Passenger_setNombre(pasajero1,pasajero2->nombre);
		Passenger_setApellido(pasajero1,pasajero2->apellido);
		Passenger_setPrecio(pasajero1,pasajero2->precio);
		Passenger_setTipoPasajero(pasajero1,pasajero2->tipoPasajero);
		Passenger_setCodigoVuelo(pasajero1,pasajero2->codigoVuelo);
		Passenger_setStatusFlight(pasajero1,pasajero2->statusFlight);
		devuelve=1;
	}
	return devuelve;
}

int cantidadPasajerosIngresados(LinkedList* this)
{
	int devuelve;
	int tam;
	int i;
	devuelve=0;
	if(this!=NULL)
	{
		Passenger* pasajeros= (Passenger*) malloc(sizeof(Passenger));
		tam=ll_len(this);
		for(i=0;i<tam;i++)
		{
			pasajeros=ll_get(this,i);
			if(pasajeros->isEmpty==1)
			{
				devuelve++;
			}
		}
		free(pasajeros);
	}
	return devuelve;
}
