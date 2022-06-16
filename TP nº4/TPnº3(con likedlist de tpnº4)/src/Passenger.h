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

/**
 * @fn Passenger Passenger_new*()
 * @brief crea una variable en memoria dinamica de tipo pasajero.
 *
 * @return devuelve un puntero a la variable creada en memoria dinamica.
 */
Passenger* Passenger_new();

/**
 * @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
 * @brief crea y carga los datos de un nuevo pasajero y lo guarda en la linkedlist
 *
 * @param idStr:ID del nuevo pasajero.
 * @param nombreStr: nombre del nuevo pasajero.
 * @param apellidoStr: apellido del nuevo pasajero.
 * @param precioStr: precio del vuelo del nuevo pasajero.
 * @param tipoPasajeroStr: tipo de pasjaero del nuevo pasajero.
 * @param codigoVueloStr: codigo de vuelo del nuevo pasajero.
 * @param statusFlightStr: estado de vuelo del nuevo pasajero.
 * @return: puntero a la variable de tipo pasajero que se creo en memoria dinamica.
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* statusFlightStr);

/**
 * @fn int Passenger_delete(Passenger*)
 * @brief cambia el campo isEmpty a 0, y muestra el pasajero que se "elimino".
 *
 * @param this: puntero a la variable pasajero del pasajero que se desea eliminar.
 * @return: devuelve 0 si el puntero viene con NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_delete(Passenger* this );

//---------------------------------------------------------FUNCIONES GET AND SET-----------------------------------------------------------------------------------

/**
 * @fn int Passenger_setId(Passenger*, int)
 * @brief guarda el valor del campo ID de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea guardar el id.
 * @param id: ID a guardar.
 * @return: devuelve 0 si el puntero viene en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_setId(Passenger* this,int id);

/**
 * @fn int Passenger_getId(Passenger*, int*)
 * @brief busca cual es el ID de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea saber su id.
 * @param id: puntero de tipo int donde se guardara el ID del pasajero anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_getId(Passenger* this,int* id);

/**
 * @fn int Passenger_setNombre(Passenger*, char*)
 * @brief guarda el valor del campo nombre de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea guardar el nombre.
 * @param nombre: nombre a guardar.
 * @return: devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_setNombre(Passenger* this,char* nombre);

/**
 * @fn int Passenger_getNombre(Passenger*, char*)
 * @brief busca cual es el nombre de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea saber su nombre.
 * @param nombre: array de char donde se guardara el nombre del pasajero anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_getNombre(Passenger* this,char* nombre);

/**
 * @fn int Passenger_setApellido(Passenger*, char*)
 * @brief guarda el valor del campo apellido de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea guardar el apellido.
 * @param apellido: apellido a guardar.
 * @return: devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_setApellido(Passenger* this,char* apellido);

/**
 * @fn int Passenger_getApellido(Passenger*, char*)
  * @brief busca cual es el apellido de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea saber su apellido.
 * @param apellido: array de char donde se guardara el apellido del pasajero anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/**
 * @fn int Passenger_setCodigoVuelo(Passenger*, char*)
 * @brief guarda el valor del campo codigoVuelo de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea guardar el codigo de vuelo.
 * @param codigoVuelo: codigo de vuelo a guardar.
 * @return: devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * @fn int Passenger_getCodigoVuelo(Passenger*, char*)
 * @brief busca cual es el codigo de vuelo de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea saber su codigo de vuelo.
 * @param codigoVuelo: array de char donde se guardara el codigo de vuelo del pasajero anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * @fn int Passenger_setTipoPasajero(Passenger*, int)
 * @brief guarda el valor del campo tipoPasajero de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea guardar el tipo de pasajero.
 * @param tipoPasajero: tipo de pasajero a guardar.
 * @return: devuelve 0 si el puntero viene con NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/**
 * @fn int Passenger_getTipoPasajero(Passenger*, int*)
 * @brief busca cual es el tipo de pasajero de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea saber su tipo de pasajero.
 * @param tipoPasajero: puntero a int donde se guardara el tipo de pasajero del pasajero anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/**
 * @fn int Passenger_setPrecio(Passenger*, float)
 * @brief guarda el valor del campo precio de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea guardar el precio.
 * @param precio: precio a guardar.
 * @return: devuelve 0 si el puntero viene con NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_setPrecio(Passenger* this,float precio);

/**
 * @fn int Passenger_getPrecio(Passenger*, float*)
 * @brief busca cual es el precio de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea saber su precio.
 * @param precio: puntero a float donde se guardara el precio del pasajero anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/**
 * @fn int Passenger_setStatusFlight(Passenger*, char*)
 * @brief guarda el valor del campo statusFlight de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea guardar el estado de vuelo.
 * @param statusFlight: estado de vuelo a guardar.
 * @return: devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_setStatusFlight(Passenger* this,char* statusFlight);

/**
 * @fn int Passenger_getStatusFlight(Passenger*, char*)
 * @brief busca cual es el estado de vuelo de un pasajero.
 *
 * @param this: puntero a tipo Passenger del pasajero que se desea saber su estado de vuelo.
 * @param statusFlight: array de char donde se guardara el estado de vuelo del pasajero anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int Passenger_getStatusFlight(Passenger* this,char* statusFlight);

//--------------------------------------------------------------------FIN FUNCIONES GET AND SET-------------------------------------------------------------------


//------------------------------------------------------------FUNCIONES PARA EL MENU DE MODIFICACIONES------------------------------------------------------------

/**
 * @fn int modificarNombre(Passenger*)
 * @brief modifica el nombre de un pasajero pidiendoselo al usuario, validando el nombre con funciones de la biblioteca "UTN".
 *
 * @param pasajeroModificar: puntero a tipo Passenger del pasajero que se desea modificar el nombre.
 * @return devuelve 0 si el puntero viene con NULL, sino devuelve 1 si todo salio bien.
 */
int modificarNombre(Passenger* pasajeroModificar);

/**
 * @fn int modificarApellido(Passenger*)
 * @brief modifica el apellido de un pasajero pidiendoselo al usuario, validando el apellido con funciones de la biblioteca "UTN".
 *
 * @param pasajeroModificar: puntero a tipo Passenger del pasajero que se desea modificar el apellido.
 * @return devuelve 0 si el puntero viene con NULL, sino devuelve 1 si todo salio bien.
 */
int modificarApellido(Passenger* pasajeroModificar);

/**
 * @fn int modificarPrecio(Passenger*)
 * @brief modifica el precio de un pasajero pidiendoselo al usuario, validando el precio con funciones de la biblioteca "UTN".
 *
 * @param pasajeroModificar: puntero a tipo Passenger del pasajero que se desea modificar el precio.
 * @return devuelve 0 si el puntero viene con NULL, sino devuelve 1 si todo salio bien.
 */
int modificarPrecio(Passenger* pasajeroModificar);

/**
 * @fn int modificarCodigoVuelo(Passenger*)
 * @brief modifica el codigo de vuelo de un pasajero pidiendoselo al usuario, validando el codigo de vuelo con funciones de la biblioteca "UTN".
 *
 * @param pasajeroModificar: puntero a tipo Passenger del pasajero que se desea modificar el codigo de vuelo.
 * @return devuelve 0 si el puntero viene con NULL, sino devuelve 1 si todo salio bien.
 */
int modificarCodigoVuelo(Passenger* pasajeroModificar);

/**
 * @fn int modificarTipoPasajero(Passenger*)
 * @brief modifica el tipo de pasajero de un pasajero pidiendoselo al usuario, validando el tipo de pasajero con funciones de la biblioteca "UTN".
 *
 * @param pasajeroModificar: puntero a tipo Passenger del pasajero que se desea modificar el tipo de pasajero.
 * @return devuelve 0 si el puntero viene con NULL, sino devuelve 1 si todo salio bien.
 */
int modificarTipoPasajero(Passenger* pasajeroModificar);

/**
 * @fn int modificarestadoVuelo(Passenger*)
 * @brief modifica el estado de vuelo de un pasajero pidiendoselo al usuario, validando el estado de vuelo con funciones de la biblioteca "UTN".
 *
 * @param pasajeroModificar: puntero a tipo Passenger del pasajero que se desea modificar el estado de vuelo.
 * @return devuelve 0 si el puntero viene con NULL, sino devuelve 1 si todo salio bien.
 */
int modificarestadoVuelo(Passenger* pasajeroModificar);

//--------------------------------------------------------------------FIN FUNCIONES PARA EL MENU DE MODIFICACIONES------------------------------------------------

//------------------------------------------------------------FUNCIONES AUXILIARES--------------------------------------------------------------------------------
/**
 * @fn int mostrarPasajero(Passenger*)
 * @brief muestra todos los datos de un solo pasajero (exepto el isEmpty).
 *
 * @param pasajero: puntero a tipo Passenger del pasajero que se desea mostrar sus datos.
 * @return devuelve 0 si el puntero viene con NULL, sino devuelve 1 si todo salio bien.
 */
int mostrarPasajero(Passenger* pasajero);

/**
 * @fn int comparaionID(Passenger*, Passenger*)
 * @brief compara si el ID de un pasajero es mayor a el ID de otro pasajero. En caso de ser asi, intercambia sus datos.
 *
 * @param pasajero1: puntero a tipo Passenger del pasajero, el cual si ID debe de ser menor.
 * @param pasajero2: puntero a tipo Passenger del pasajero, el cual si ID debe de ser mayor.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int comparaionID(Passenger* pasajero1,Passenger* pasajero2);

/**
 * @fn int cambioPasajero(Passenger*, Passenger*)
 * @brief intercambia el valor de los campos de 2 pasajeros.
 *
 * @param pasajero1: puntero a tipo Passenger de un pasajero.
 * @param pasajero2: puntero a tipo Passenger del otro pasajero.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int cambioPasajero(Passenger* pasajero1,Passenger* pasajero2);

/**
 * @fn int cantidadPasajerosIngresados(LinkedList*)
 * @brief calcula la cantidad de pasajeros que estan ingresados. Es decir, cuyos isEmpty sean = a 1.
 *
 * @param this: puntero a la LinkedList donde se buscara la cantidad de pasajeros que estan ingresados.
 * @return devuelve -1 si el puntero viene en NULL, sino devuelve la cantidad de pasjaeros que estan ingresados(0=no hay pasajeros ingresados).
 */
int cantidadPasajerosIngresados(LinkedList* this);

/**
 * @fn int savePasajerosArchivo(Passenger*, FILE*, LinkedList*)
 * @brief guarda los datos de todos los pasajeros que estan en la LinkedList en un archivo.
 *
 * @param pasajero: puntero a una variable dinamica de tipo Passenger, la cual se usara para subir los datops al archivo.
 * @param pFile: archivo donde se guardaran los datos de los pasjaeros.
 * @param this: LinkedList donde estan los datos de los pasajeros que se van a guardar en el archivo.
 * @return
 */
int savePasajerosArchivo(Passenger* pasajero, FILE* pFile, LinkedList* this);

/**
 * @fn int pedirDatosPasajeros(Passenger*, char*, char*, char*, char*, char*, int*)
 * @brief le pide al usuario los datos del nuevo pasajero (a exepcion del ID y el campo isEmpty) y los valida con funciones de la biblioteca "UTN".
 *
 * @param pPasajero: puntero a tipo Passenger donde se guardaran los datos del nuevo apsajero.
 * @param nombre: array de char donde se guardara el nombre ingresado.
 * @param apellido: array de char donde se guardara el apellido ingresado.
 * @param precio: array de char donde se guardara el precio ingresado.
 * @param codigoVuelo: array de char donde se guardara el codigo de vuelo ingresado.
 * @param tipoPasajero: array de char donde se guardara el tipo de pasajero ingresado.
 * @param statusFlight: puntero a int donde se guardara el estado de vuelo ingresado.
 * @return devuelve 0 si cualquiera de los punteros vienen en NULL, sino devuelve 1 si todo salio bien.
 */
int pedirDatosPasajeros(Passenger* pPasajero,char* nombre,char* apellido,char* precio,char* codigoVuelo,char* tipoPasajero,int* statusFlight);

//--------------------------------------------------------------------FIN FUNCIONES AUXILIARES--------------------------------------------------------------------


#endif /* PASSENGER_H_ */
