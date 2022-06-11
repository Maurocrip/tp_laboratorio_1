#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"
#include "UTN.h"

//-------------------------------------------FUNCIONES PARA CARGAR DATOS DEL ARCHIVO DATA.CSV------------------------------------------------------------------------------------------------------


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
	int pasajerosArchiuvo;
	int i;
	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		Passenger* pPasajero=Passenger_new();

		pArchivo=fopen(path,"r");
		if(pArchivo==NULL)
		{
			printf("\nEl archivo no se pudo abrir\n");
			exit (1);
		}

		cantidad=ll_len(pArrayListPassenger);
		if(cantidad>0)
		{
			pasajerosArchiuvo=parser_PassengerFromText(pArchivo,pArrayListPassenger);
			printf("\n\nSe le modifico el ID a:\n");
			for(i=0;i<cantidad;i++)
			{
				pPasajero=ll_get(pArrayListPassenger,i);
				if(pPasajero->isEmpty==1)
				{
					pPasajero->id=pPasajero->id+pasajerosArchiuvo;
					printf("ID:%d\tNom:%s\tApe:%s\tPre:%2.f\tCodVuel:%s\tTipPasa:%d\tEstadoVuel:%s\n"//no uso la funcion mostrarPasajeros por que sino no aparecen todos los pasajeros en pantalla
							,pPasajero->id,pPasajero->nombre,pPasajero->apellido,pPasajero->precio,pPasajero->codigoVuelo,pPasajero->tipoPasajero,pPasajero->statusFlight);
				}
			}
		}
		else
		{
			parser_PassengerFromText(pArchivo,pArrayListPassenger);
		}
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
	int pasajerosArchiuvo;
	int i;
	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		Passenger* pPasajero=Passenger_new();

		pArchivo=fopen(path,"r");
		if(pArchivo==NULL)
		{
			printf("\n\nSe le modifico el ID a:\n");
			exit (1);
		}

		cantidad=ll_len(pArrayListPassenger);
		if(cantidad>0)
		{
			pasajerosArchiuvo=parser_PassengerFromText(pArchivo,pArrayListPassenger);
			printf("\nSe le modifico el ID a:\n");
			for(i=0;i<cantidad;i++)
			{
				pPasajero=ll_get(pArrayListPassenger,i);
				if(pPasajero->isEmpty==1)
				{
					pPasajero->id=pPasajero->id+pasajerosArchiuvo;
					printf("\nID:%d\tNom:%s\tApe:%s\tPre:%2.f\tCodVuel:%s\tTipPasa:%d\tEstadoVuel:%s" //no uso la funcion mostrarPasajeros por que sino no aparecen todos los pasajeros en pantalla
							,pPasajero->id,pPasajero->nombre,pPasajero->apellido,pPasajero->precio,pPasajero->codigoVuelo,pPasajero->tipoPasajero,pPasajero->statusFlight);
				}
			}
		}
		else
		{
			parser_PassengerFromText(pArchivo,pArrayListPassenger);
		}
		fclose(pArchivo);
	}
	return 1;
}

//--------------------------------------------------------------------FIN FUNCIONES PARA CARGAR DATOS DEL ARCHIVO DATA.CSV------------------------------------------------------------------------

//-------------------------------------------FUNCIONES ALTA, BAJA, MODIFICACION, ELIMINACION Y ORDENAMIENTO DE PASAJEROS--------------------------------------------------------------------------


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
		Passenger* pPasajero=Passenger_new();
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

		devuelve=pedirDatosPasajeros(pPasajero,var2,var3,var4,var5,var6,&var7);

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
		Passenger* pPasajeroModificar=Passenger_new();
		tam=ll_len(pArrayListPassenger);
		do
		{
			UTN_getValidacionMaximoMinimo(&id,"\nIngrese el ID del pasajero que desea modificar: ","ERROR, numero de ID invalido\n"
				"ingrese el ID del pasajero que desea modificar: ",0,tam);
			for(i=0;i<tam;i++)
			{
				pPasajeroModificar=ll_get(pArrayListPassenger,0);
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
		mostrarPasajero(pPasajeroModificar);
//-------------------------------------------MENU DE MODIFICACIONES--------------------------------------------------------------------------------------------------------------------------------
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
		Passenger* pPasajeroModificar=Passenger_new();
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
					printf("\n%d", pPasajeroModificar->id);
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
		Passenger* pPasajero=Passenger_new();
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
		Passenger* pPasajero=Passenger_new();
		Passenger* pPasajero2=Passenger_new();
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

//-------------------------------------------FIN FUNCIONES ALTA, BAJA, MODIFICACION, ELIMINACION Y ORDENAMIENTO DE PASAJEROS-----------------------------------------------------------------------

//-------------------------------------------FUNCIONES PARA GUARDAR DATOS DEL ARCHIVO DATA.CSV-----------------------------------------------------------------------------------------------------


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int devuelve;
	devuelve=0;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pArchivo;
		Passenger* pasajero=Passenger_new();

		pArchivo=fopen(path,"wb");
		if(pArchivo==NULL)
		{
			printf("\nEl archivo no se pudo abrir\n");
			exit (1);
		}

		devuelve=savePasajerosArchivo(pasajero,pArchivo,pArrayListPassenger);

		free(pasajero);
		fclose(pArchivo);
	}

	return devuelve;

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
		FILE* pArchivo;
		Passenger* pasajero=Passenger_new();

		pArchivo=fopen(path,"wb");
		if(pArchivo==NULL)
		{
			printf("\nEl archivo no se pudo abrir\n");
			exit (1);
		}

		devuelve=savePasajerosArchivo(pasajero,pArchivo,pArrayListPassenger);

		free(pasajero);
		fclose(pArchivo);
	}

	return devuelve;
}

//--------------------------------------------------------------------FIN FUNCIONES PARA GUARDAR DATOS DEL ARCHIVO DATA.CSV------------------------------------------------------------------------
