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

int chearLetraint(char* array, int tam);

int UTN_GetValor(char* array, int tam, char* mensaje, char* mensajeError, int conNumero);

int UTN_getValidacionMayorfloat(char* resultado, char* mensaje,char* mensajeError, int numero);

#endif /* UTN_H_ */
