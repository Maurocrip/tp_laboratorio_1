/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define CARACTERES 50

typedef struct
{
	int id;
	char nombre[CARACTERES];
	char apellido[CARACTERES];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	char statusFlight[CARACTERES];
	int isEmpty;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* statusFlightStr);
int Passenger_delete(Passenger* this );

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setStatusFlight(Passenger* this,char* statusFlight);
int Passenger_getStatusFlight(Passenger* this,char* statusFlight);


int modificarNombre(Passenger* pasajeroModificar);
int modificarApellido(Passenger* pasajeroModificar);
int modificarPrecio(Passenger* pasajeroModificar);
int modificarCodigoVuelo(Passenger* pasajeroModificar);
int modificarTipoPasajero(Passenger* pasajeroModificar);
int modificarestadoVuelo(Passenger* pasajeroModificar);

int mostrarPasajero(Passenger* pasajero);
int comparaionID(Passenger* pasajero1,Passenger* pasajero2);
int cambioPasajero(Passenger* pasajero1,Passenger* pasajero2);
int cantidadPasajerosIngresados(LinkedList* this);
int savePasajerosArchivo(Passenger* pasajero, FILE* pFile, LinkedList* this);
int pedirDatosPasajeros(Passenger* pPasajero,char* nombre,char* apellido,char* precio,char* codigoVuelo,char* tipoPasajero,int* statusFlight);


#endif /* PASSENGER_H_ */
