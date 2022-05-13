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

/**
 * @fn void alta(Passenger, int, Passenger*, int);
 * @brief le permite ingresar un pasajero al usuario.
 *
 * @param persona: la variable donde se va a guardos los daos que ingrese el usuario.
 * @param id: el ID que le correspondo al nuevo pasajero.
 * @param guardar: la variable donde estara la lsita de todos los pasajeros ingresados.
 * @param tam: el tamño de la lista de los pasajeros.
 */
void alta(Passenger persona, int id, Passenger* guardar, int tam);

/**
 * @fn void modificacion(Passenger*, int);
 * @brief le permite al usuario modificar los datos de un pasajero por su ID.
 *
 * @param guardar: la variable donde estara la lsita de todos los pasajeros ingresados.
 * @param tam: el tamño de la lista de los pasajeros.
 */
void modificacion(Passenger* guardar, int tam);

/**
 * @fn void modificarNombre(Passenger*, int, int);
 * @brief le permite al usuario modificar el nombre de un pasajero.
 *
 * @param guardar: variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param tam: el tamaño de la variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param indice: la posicion del array donde se encuentra el pasajero.
 */
void modificarNombre(Passenger* guardar, int tam, int indice);

/**
 * @fn void modificarApellido(Passenger*, int, int);
 * @brief le permite al usuario modificar el apellido de un pasajero.
 *
 * @param guardar: variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param tam: el tamaño de la variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param indice: la posicion del array donde se encuentra el pasajero.
 */
void modificarApellido(Passenger* guardar, int tam, int indice);

/**
 * @fn void modificarPrecio(Passenger*, int, int);
 * @brief le permite al usuario modificar el precio de un pasajero.
 *
 * @param guardar: variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param tam: el tamaño de la variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param indice: la posicion del array donde se encuentra el pasajero.
 */
void modificarPrecio(Passenger* guardar, int tam, int indice);

/**
 * @fn void modificarTipoPasajero(Passenger*, int, int);
 * @brief le permite al usuario modificar el tipo de pasajero de un pasajero.
 *
 * @param guardar: variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param tam: el tamaño de la variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param indice: la posicion del array donde se encuentra el pasajero.
 */
void modificarTipoPasajero(Passenger* guardar, int tam, int indice);

/**
 * @fn void modificarCodigo(Passenger*, int, int);
 * @brief le permite al usuario modificar el codigo de un pasajero.
 *
 * @param guardar: variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param tam: el tamaño de la variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param indice: la posicion del array donde se encuentra el pasajero.
 */
void modificarCodigo(Passenger* guardar, int tam, int indice);

/**
 * @fn void modificarEstadoDeVuelo(Passenger*, int, int);
 * @brief le permite al usuario modificar el estado de vuelo de un pasajero.
 *
 * @param guardar: variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param tam: el tamaño de la variable donde se encuentran los datos del pasajero que se quiera modificar.
 * @param indice: la posicion del array donde se encuentra el pasajero.
 */
void modificarEstadoDeVuelo(Passenger* guardar, int tam, int indice);

/**
 * @fn void baja(Passenger*, int);
 * @brief le permite al usuario dar de baja(eliminar) a un pasajero por su ID.
 *
 * @param lista: la variable donde estara la lsita de todos los pasajeros ingresados.
 * @param tam: el tamño de la lista de los pasajeros.
 */
void baja(Passenger* lista, int tam);

/**
 * @fn void informar(Passenger*, int);
 * @brief le muestar al usuario un sub menu, el cual tiene 3 opciones de listados:
 * 1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
 * 2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
 * 3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.
 *
 * @param lista: la variable donde estara la lsita de todos los pasajeros ingresados.
 * @param tam: el tamño de la lista de los pasajeros.
 */
void informar(Passenger* lista, int tam);

/**
 * @fn int printPassengerPorEstadoVuelo(Passenger*, int);
 * @brief le muestar al usuario aquellos pasajeros que tienen vuelo "ACTIVO".
 *
 * @param list: la variable donde estara la lsita de todos los pasajeros ingresados.
 * @param length: el tamño de la lista de los pasajeros.
 * @return devuelve -1 si el array es null o el tamaño es menor a 0, y devuelve o si todo esta ok.
 */
int printPassengerPorEstadoVuelo(Passenger* list, int length);

/**
 * @fn float totalPrecioPasajeros(Passenger*, int);
 * @brief determina cual es el precio total  sumando el precio de todos los pasajeros ingresados.
 *
 * @param list: la variable donde estara la lsita de todos los pasajeros ingresados.
 * @param length: el tamño de la lista de los pasajeros.
 * @return devuelve 0 si no se pudo hacer la suma, sino devuelve el precio total.
 */
float totalPrecioPasajeros(Passenger* list, int length);

/**
 * @fn int cantidadPasajeros(Passenger*, int);
 * @brief determina cual es la cantidad de los pasajeros ingresados.
 *
 * @param list: la variable donde estara la lsita de todos los pasajeros ingresados.
 * @param length: el tamño de la lista de los pasajeros.
 * @return devuelve la cantidad de pasajeros.
 */
int cantidadPasajeros(Passenger* list, int length);

/**
 * @fn int cantidadPasajerosSuperanPrecioPromedio(Passenger*, int);
 * @brief determina cual es la cantidad de los pasajeros ingresados que superan el precio promedio.
 *
 * @param list: la variable donde estara la lsita de todos los pasajeros ingresados.
 * @param length: el tamño de la lista de los pasajeros.
 * @return devuelve la cantidad de pasajeros.
 */
int cantidadPasajerosSuperanPrecioPromedio(Passenger* list, int length, float precioPromedio);

/**
 *@fn void cargaForzada(Passenger*, int);
 * @brief realiza una carga forzada de los datos de 2 pasajeros.
 *
 * @param list: la variable donde estaran los 2 pasajeros harcodeados.
 * @param length: el tamño del array donde se encuentran los pasajeros harcodeados.
 */
void cargaForzada(Passenger* list, int length);









#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_



#endif /* ARRAYPASSENGER_H_ */
