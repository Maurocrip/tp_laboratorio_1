/*
 * ArrayPassenger.h
 *
 *  Created on: 7 may. 2022
 *      Author: Usuario
 */
#define IDENTIFICACION 51
#define CODIGO 10

struct
{
	int id;
	char name[IDENTIFICACION];
	char lastName[IDENTIFICACION];
	float price;
	char flycode[CODIGO];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}typedef Passenger;

/**
* @fn int initPassengers(Passenger*, int);
* @brief To indicate that all position in the array are empty, this function put the flag (isEmpty)
* in TRUE in all position of the array.
*
* @param list Passenger* Pointer to array of passenger.
* @param len int Array length.
* @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*/
int initPassengers(Passenger* list, int len);

/**
* @fn int addPassenger(Passenger*, int, int, char[], char[], float, int, char[]);
* @brief add in a existing list of passengers the values received as parameters in the first empty position.
*
* @param list passenger*.
* @param len int.
* @param id int.
* @param name[] char.
* @param lastName[] char.
* @param price float.
* @param typePassenger int.
* @param flycode[] char.
* @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok.
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);

/**
* @fn int findPassengerById(Passenger*, int, int);
* @brief find a Passenger by Id en returns the index position in array.
*
* @param list Passenger*.
* @param len int.
* @param id int.
* @return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found].
*/
int findPassengerById(Passenger* list, int len,int id);

/**
* @fn int removePassenger(Passenger*, int, int);
* @brief Remove a Passenger by Id (put isEmpty Flag in 1).
*
* @param list Passenger*.
* @param len int.
* @param id int.
* @return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok.
*/
int removePassenger(Passenger* list, int len, int id);

/**
* @fn int sortPassengers(Passenger*, int, int);
* @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* @param list Passenger*.
* @param len int.
* @param order int [1] indicate UP - [0] indicate DOWN.
* @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*/
int sortPassengers(Passenger* list, int len, int order);

/**
* @fn int printPassenger(Passenger*, int);
* @brief print the content of passengers array.
*
* @param list Passenger*.
* @param length int.
* @return int.
*/
int printPassenger(Passenger* list, int length);

/**
* @fn int sortPassengersByCode(Passenger*, int, int);
* @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order.
*
* @param list Passenger*.
* @param len int.
* @param order int [1] indicate UP - [0] indicate DOWN.
* @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*/
int sortPassengersByCode(Passenger* list, int len, int order);


void alta(Passenger persona, int id, Passenger* guardar, int tam);


void modificacion(Passenger* guardar, int tam);


void modificarNombre(Passenger* guardar, int tam, int indice);


void modificarApellido(Passenger* guardar, int tam, int indice);


void modificarPrecio(Passenger* guardar, int tam, int indice);

void modificarTipoPasajero(Passenger* guardar, int tam, int indice);

void modificarCodigo(Passenger* guardar, int tam, int indice);

void modificarEstadoDeVuelo(Passenger* guardar, int tam, int indice);

void baja(Passenger* lista, int tam);

void informar(Passenger* lista, int tam);

int printPassengerPorEstadoVuelo(Passenger* list, int length);

float totalPrecioPasajeros(Passenger* list, int length);

int cantidadPasajeros(Passenger* list, int length);

int cantidadPasajerosSuperanPrecioPromedio(Passenger* list, int length, float precioPromedio);

void cargaForzada(Passenger* list, int length);









#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_



#endif /* ARRAYPASSENGER_H_ */
