/*
 * UTN.h
 *
 *  Created on: 6 jun. 2022
 *      Author: Usuario
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * @fn int UTN_getValidacionMaximoMinimo(int*, char*, char*, int, int);
 * @brief le pide al usuario un numero de tipo int y lo valida entre un maximo y un minimo.
 *
 * @param resultado: variable donde se guardara el numero ingresado por el usuario.
 * @param mensaje: el mensaje que se mostrara antes de que el usuario ingrese un dato.
 * @param mensajeError: el mensaje que se mostrara cuando el usuario ingrese un dato invalido.
 * @param minimo: el numero minimo por el cual se validara el dato ingresado.
 * @param maximo: el numero maximo por el cual se validara el dato ingresado.
 * @return devuelve 0.
 */
int UTN_getValidacionMaximoMinimo(int* resultado, char* mensaje,char* mensajeError, int minimo, int maximo);

/**
 * @fn int chearLetraint(char*, int);
 * @brief chequea si un string tiene letras ingresadas.
 *
 * @param array: array donde se encuentra el string.
 * @param tam: tamaño del array.
 * @return devuelve -1 si el array es invalido o el tamño es mayor a 0, devuelve 0 si no contiene letras o simbolos,
 y devuelve un numero mayor a 0 si contine alguna letra o simbolo.
 */
int chearLetraint(char* array, int tam);

/**
 * @fn int UTN_GetValor(char*, int, char*, char*, int);
 * @brief le pide al usuario un dato de tipo string y valida que no contenga un numero si es que se lo requiere.
 *
 * @param array: el array de caracteres donde se guardara el dato ingresado.
 * @param tam: el tamaño del array.
 * @param mensaje: el mensaje que se mostrara antes de que el usuario ingrese un dato.
 * @param mensajeError: el mensaje que se mostrara cuando el usuario ingrese un dato invalido.
 * @param conNumero: se ingresa 0 si se desea uqe el dato ingresado no lleve numeros.
 * @return devuelve -1 si no si el array es invalido o el tamaño es menor que 0, y devuelve 0 si se pudo pedir el dato.
 */
int UTN_GetValor(char* array, int tam, char* mensaje, char* mensajeError, int conNumero);

/**
 * @fn int UTN_getValidacionMayorfloat(char*, char*, char*, int);
 * @brief le pide al usuario un numero de tipo float y valida si es menor que un numero.
 *
 * @param resultado: array de char donde se guardara el numero ingresado por el usuario.
 * @param mensaje: el mensaje que se mostrara antes de que el usuario ingrese un dato.
 * @param mensajeError: el mensaje que se mostrara cuando el usuario ingrese un dato invalido.
 * @param numero: numero por el cual va a ser validado el dato ingresado.
 * @return devuelve 0.
 */
int UTN_getValidacionMayorfloat(char* resultado, char* mensaje,char* mensajeError, int numero);

/**
 * @fn int UTN_getValidacionMayorInt(int*, char*, char*, int);
 * @brief le pide al usuario un numero de tipo int y valida si es menor que un numero.
 *
 * @param resultado: variable donde se guardara el numero ingresado por el usuario.
 * @param mensaje: el mensaje que se mostrara antes de que el usuario ingrese un dato.
 * @param mensajeError: el mensaje que se mostrara cuando el usuario ingrese un dato invalido.
 * @param numero: numero por el cual va a ser validado el dato ingresado.
 * @return devuelve 0.
 */
int UTN_getValidacionMayorInt(int* resultado, char* mensaje,char* mensajeError, int numero);

/***
 * @fn void convertirPalabraAMayusculas(char*, int);
 * @brief combierte un td el string a mayuscula.
 *
 * @param comprobar: array donde se encuentra el string.
 * @param tam: tamaño del array.
 */
void convertirPalabraAMayusculas(char* comprobar, int tam);

#endif /* UTN_H_ */
