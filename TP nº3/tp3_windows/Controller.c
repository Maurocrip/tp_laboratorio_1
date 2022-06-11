#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"
#include "UTN.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int cantidad;
	int i;
	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		Passenger* pPasajero= (Passenger*) malloc(sizeof(Passenger));

		pArchivo=fopen(path,"r");
		if(pArchivo==NULL)
		{
			printf("\nEl archivo no se pudo abrir\n");
			exit (1);
		}

		cantidad=ll_len(pArrayListPassenger);
		if(cantidad>0)
		{
			for(i=0;i<cantidad;i++)
			{
				pPasajero=ll_get(pArrayListPassenger,i);
				if(pPasajero->isEmpty==1)
				{
					pPasajero->id=pPasajero->id+1000;
					printf("\nID:%d\tNom:%s\tApe:%s\tPre:%2.f\tCodVuel:%s\tTipPasa:%d\tEstadoVuel:%s\nSe le modifico el ID\n"
							,pPasajero->id,pPasajero->nombre,pPasajero->apellido,pPasajero->precio,pPasajero->codigoVuelo,pPasajero->tipoPasajero,pPasajero->statusFlight);
				}
			}
		}

		parser_PassengerFromText(pArchivo,pArrayListPassenger);
		fclose(pArchivo);
	}

    return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int cantidad;
	int i;
	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		Passenger* pPasajero= (Passenger*) malloc(sizeof(Passenger));

		pArchivo=fopen(path,"r");
		if(pArchivo==NULL)
		{
			printf("\nEl archivo no se pudo abrir\n");
			exit (1);
		}

		cantidad=ll_len(pArrayListPassenger);
		if(cantidad>0)
		{
			for(i=0;i<cantidad;i++)
			{
				pPasajero=ll_get(pArrayListPassenger,i);
				if(pPasajero->isEmpty==1)
				{
					pPasajero->id=pPasajero->id+1000;
					printf("\nID:%d\tNom:%s\tApe:%s\tPre:%2.f\tCodVuel:%s\tTipPasa:%d\tEstadoVuel:%s\nSe le modifico el ID\n"
							,pPasajero->id,pPasajero->nombre,pPasajero->apellido,pPasajero->precio,pPasajero->codigoVuelo,pPasajero->tipoPasajero,pPasajero->statusFlight);
				}
			}
		}

		parser_PassengerFromBinary(pArchivo,pArrayListPassenger);
		fclose(pArchivo);
	}
	return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int devuelve;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];
	int var7;
	devuelve=0;

	if(pArrayListPassenger!=NULL)
	{
		Passenger* pPasajero= (Passenger*) malloc(sizeof(Passenger));
		devuelve=1;
		pPasajero->id=ll_len(pArrayListPassenger);
		if(pPasajero->id==0)
		{
			strcpy(var1,"1");
		}
		else
		{
			pPasajero->id++;
			itoa(pPasajero->id,var1,10);
		}

		UTN_GetValor(var2,CARACTERES,"Ingrese su nombre: ",
				"\nERROR, su nombre no puede contener numeros o excederse de los 50 caracteres\nIngrese su nombre: ",0);
		UTN_GetValor(var3,CARACTERES,"Ingrese su apellido: ",
					"\nERROR, su apellido no puede contener numeros o excederse de los 50 caracteres\nIngrese su apellido: ",0);
		UTN_getValidacionMayorfloat(var4,"Ingrese el precio del vuelo: ",
				"\nERROR, el precio del vuelo no puede contener letras o ser menor a 0\nIngrese el precio del vuelo: ",0);
		UTN_GetValor(var5,7,"Ingrese su codigo de vuelo: ",
					"\nERROR, su codigo de vuelo no excederse de los 7 caracteres\nIngrese codigo de vuelo: ",1);
		convertirPalabraAMayusculas(var5,7);
		UTN_getValidacionMaximoMinimo(&pPasajero->tipoPasajero,"Ingrese el tipo de pasajero(1=FirstClass 2=ExecutiveClass 3=EconomyClass): ",
				"\nERROR, Reingrese un numero valido(1-3)\nIngrese el tipo de pasajero(1=FirstClass 2=ExecutiveClass 3=EconomyClass): ", 1, 3);
		itoa(pPasajero->tipoPasajero,var6,50);
		UTN_getValidacionMaximoMinimo(&var7,"Ingrese el estado de vuelo(1=Aterrizado 2=En horario 3=Demorado): ",
				"\nERROR, Reingrese solo un numero valido(1-3)\nIngrese el estado de vuelo(1=Aterrizado 2=En horario 3=Demorado): ", 1, 3);
		switch(var7)
		{
			case 1:
				strcpy(pPasajero->statusFlight,"Aterrizado");
			break;

			case 2:
				strcpy(pPasajero->statusFlight,"En horario");
			break;

			case 3:
				strcpy(pPasajero->statusFlight,"Demorado");
			break;
		}

		pPasajero=Passenger_newParametros(var1,var2,var3,var4,var5,var6,pPasajero->statusFlight);
		mostrarPasajero(pPasajero);
		ll_add(pArrayListPassenger,pPasajero);
	}

    return devuelve;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int chequeo;
	int tam;
	int opcion;
	int i;
	int id;

	if(pArrayListPassenger!=NULL)
	{
		Passenger* pPasajeroModificar= (Passenger*) malloc(sizeof(Passenger));
		tam=ll_len(pArrayListPassenger);
		do
		{
			UTN_getValidacionMaximoMinimo(&id,"\nIngrese el ID del pasajero que desea modificar: ","ERROR, numero de ID invalido\n"
				"ingrese el ID del pasajero que desea modificar: ",0,tam);
			for(i=0;i<tam;i++)
			{
				pPasajeroModificar=ll_get(pArrayListPassenger,i);
				if(pPasajeroModificar->id==id)
				{
					break;
				}
			}

			if(pPasajeroModificar->isEmpty!=1)
			{
				printf("\nEl pasajero con ID %d se ah eliminado anteriormente\n",id);
			}
		}while(pPasajeroModificar->isEmpty!=1);
		/*printf("\nID:%d \nNombre:%s \nApellido:%s \nPrecio:%f \nCodigo de Vuelo:%s \nTipo de pasajero:%d \nEstado de vuelo:%s",
				pPasajeroModificar->id,pPasajeroModificar->nombre,pPasajeroModificar->apellido,pPasajeroModificar->precio,pPasajeroModificar->codigoVuelo,pPasajeroModificar->tipoPasajero,pPasajeroModificar->statusFlight);*/
		mostrarPasajero(pPasajeroModificar);
//-------------------------------------------MENU DE MODIFICACIONES----------------------------------------------------------------------------------------------------------------------------------------------------------
		do{
			UTN_getValidacionMaximoMinimo(&opcion,"\nIngrese un numero \n"
							" 1. para modificar el nombre\n"
							" 2. para modificar el apelllido\n"
							" 3. para modificar el precio\n"
							" 4. para modificar el Codigo de Vuelo \n"
							" 5. para modificar el Tipo de pasajero\n"
							" 6. para modificar el Estado de vuelo\n"
							" 7. salir\n", "\nERROR, Reingrese un numero valido(1-7)\n"
											" 1. para modificar el nombre\n"
											" 2. para modificar el apelllido\n"
											" 3. para modificar el precio\n"
											" 4. para modificar el Codigo de Vuelo \n"
											" 5. para modificar el Tipo de pasajero\n"
											" 6. para modificar el Estado de vuelo\n"
											" 7. salir", 1, 7);
			 switch(opcion)
		      {
				case 1:
					chequeo=modificarNombre(pPasajeroModificar);
					if(chequeo==0)
					{
						printf("\nNo se pudo modificar el nombre\n");
					}
				break;

				case 2:
					chequeo=modificarApellido(pPasajeroModificar);
					if(chequeo==0)
					{
						printf("\nNo se pudo modificar el apellido\n");
					}
				break;

				case 3:
				   chequeo=modificarPrecio(pPasajeroModificar);
				   if(chequeo==0)
				   {
					   printf("\nNo se pudo modificar el precio\n");
				   }
				break;
				case 4:
					chequeo=modificarCodigoVuelo(pPasajeroModificar);
					if(chequeo==0)
				   {
					   printf("\nNo se pudo modificar el codigo de vuelo\n");
				   }
				break;

				case 5:
					chequeo=modificarTipoPasajero(pPasajeroModificar);
					if(chequeo==0)
				    {
					    printf("\nNo se pudo modificar el tipo de pasajero\n");
				    }
				break;

				case 6:
					chequeo=modificarestadoVuelo(pPasajeroModificar);
					if(chequeo==0)
					{
						printf("\nNo se pudo modificar el estado de vuelo\n");
				    }
				break;
		      }

		    }while(opcion != 7);
	}

	return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int devuelve;
	int chequeo;
	int tam;
	int i;
	int id;
	devuelve=0;
	if(pArrayListPassenger!=NULL)
	{
		Passenger* pPasajeroModificar= (Passenger*) malloc(sizeof(Passenger));
		devuelve=1;
		tam=ll_len(pArrayListPassenger);
		do
		{
			UTN_getValidacionMaximoMinimo(&id,"\nIngrese el ID del pasajero que desea eliminar: ","ERROR, numero de ID invalido\n"
				"ingrese el ID del pasajero que desea eliminar: ",0,tam);
			for(i=0;i<tam;i++)
			{
				pPasajeroModificar=ll_get(pArrayListPassenger,i);
				if(pPasajeroModificar->id==id)
				{
					break;
				}
			}
			if(pPasajeroModificar->isEmpty!=1)
			{
				printf("\nEl pasajero con ID %d ya habia sido eliminado\n",id);
			}
		}while(pPasajeroModificar->isEmpty!=1);
		chequeo=Passenger_delete(pPasajeroModificar);
		if(chequeo==0)
		{
			printf("\nNo se pudo eliminar el pasajero\n");
		}
	}
    return devuelve;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int tam;
	int i;
	int devuelve;
	devuelve=0;
	if(pArrayListPassenger!=NULL)
	{
		devuelve=1;
		Passenger* pPasajero= (Passenger*) malloc(sizeof(Passenger));
		tam=ll_len(pArrayListPassenger);
		for(i=0;i<tam;i++)
		{
			pPasajero=ll_get(pArrayListPassenger,i);
			if(pPasajero->isEmpty==1)
			{
				mostrarPasajero(pPasajero);
			}
		}
	}
    return devuelve;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{

	int tam;
	int i;
	int j;
	int devuelve;
	devuelve=0;
	if(pArrayListPassenger!=NULL)
	{
		devuelve=1;
		Passenger* pPasajero= (Passenger*) malloc(sizeof(Passenger));
		Passenger* pPasajero2= (Passenger*) malloc(sizeof(Passenger));
		tam=ll_len(pArrayListPassenger);
		if(tam!=1)
		{
			for(i=0;i<tam;i++)
			{
				pPasajero=ll_get(pArrayListPassenger,i);
				for(j=i;j<tam;j++)
				{
					pPasajero2=ll_get(pArrayListPassenger,j);
					comparaionID(pPasajero,pPasajero2);
				}
			}
		}
		free(pPasajero);
		free(pPasajero2);
	}
	return devuelve;

}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int devuelve;
	devuelve=0;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		devuelve=1;
		FILE* pArchivo;
		int tam;
		Passenger* pasajero= (Passenger*) malloc(sizeof(Passenger));
		tam=ll_len(pArrayListPassenger);
		pArchivo=fopen(path,"w");
		if(pArchivo==NULL)
		{
			printf("\nEl archivo no se pudo abrir\n");
			exit (1);
		}

		fprintf(pArchivo,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(int i=0;i<tam;i++)
		{
			pasajero=ll_get(pArrayListPassenger,i);
			if(pasajero->isEmpty==1)
			{
				fprintf(pArchivo,"%d,%s,%s,%f,%s,%d,%s\n",pasajero->id,pasajero->nombre,
					pasajero->apellido,pasajero->precio,pasajero->codigoVuelo,pasajero->tipoPasajero,pasajero->statusFlight);
			}
		}
		free(pasajero);
		fclose(pArchivo);
	}

	return devuelve;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int devuelve;
	devuelve=0;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		devuelve=1;
		FILE* pArchivo;
		int tam;
		Passenger* pasajero= (Passenger*) malloc(sizeof(Passenger));
		tam=ll_len(pArrayListPassenger);
		pArchivo=fopen(path,"wb");
		if(pArchivo==NULL)
		{
			printf("\nEl archivo no se pudo abrir\n");
			exit (1);
		}

		fprintf(pArchivo,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(int i=0;i<tam;i++)
		{
			pasajero=ll_get(pArrayListPassenger,i);
			if(pasajero->isEmpty==1)
			{
				fprintf(pArchivo,"%d,%s,%s,%f,%s,%d,%s\n",pasajero->id,pasajero->nombre,
					pasajero->apellido,pasajero->precio,pasajero->codigoVuelo,pasajero->tipoPasajero,pasajero->statusFlight);
			}
		}
		free(pasajero);
		fclose(pArchivo);
	}

	return devuelve;
}
