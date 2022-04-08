/*
 * calculos.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Usuario
 */

float get_descuento(float precio, int descuento)
{
	float precioConDescuento;

	precioConDescuento= precio - (precio*descuento)/100;

	return precioConDescuento;
}
float get_interes(float precio, int interes)
{
	float precioConInteres;

	precioConInteres= precio + (precio*interes)/100;

	return precioConInteres;
}
float get_PesosABitcoin(float pesos)
{
	float resultado;

	resultado = pesos / 4606954.55;

	return resultado;
}

float get_unitario(float cantidad, float precio)
{
	float resultado;

	resultado = precio /cantidad;

	return resultado;
}
float get_resta(float n1, float n2)
{
	float respuesta;

	respuesta = n1 -n2;

	return respuesta;
}

float get_cambioSigno(float numero)
{
	float resultado;

	resultado=numero * (-1);

	return resultado;
}
