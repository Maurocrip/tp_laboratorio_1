#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "UTN.h"

/*--------------------------------------------------------------------------------------------------------------------------------------------
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
---------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int chequeo;
    int archivoFlag = 0;
    int tam;
    int guardado =0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	UTN_getValidacionMaximoMinimo(&option,"\nIngrese un numero \n"
					" 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
					" 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
					" 3. Alta de pasajero\n"
					" 4. Modificar datos de pasajero\n"
					" 5. Baja de pasajero\n"
					" 6. Listar pasajeros\n"
					" 7. Ordenar pasajeros\n"
					" 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
					" 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
					" 10. salir ", "\nERROR, Reingrese un numero valido(1-10)\n"
							" 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
								" 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
								" 3. Alta de pasajero\n"
								" 4. Modificar datos de pasajero\n"
								" 5. Baja de pasajero\n"
								" 6. Listar pasajeros\n"
								" 7. Ordenar pasajeros\n"
								" 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
								" 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
								" 10. salir ", 1, 10);
    	tam=cantidadPasajerosIngresados(listaPasajeros);

        switch(option)
        {
            case 1:
            	if(archivoFlag==0)
            	{
            		controller_loadFromText("data.csv",listaPasajeros);
            		archivoFlag=1;
            	}
            	else
            	{
            		printf("\nYa has cargado el archivo anteriormente\n");
            	}
            break;

            case 2:
            	if(archivoFlag==0)
				{
            		controller_loadFromBinary("data.csv",listaPasajeros);
					archivoFlag=1;
				}
				else
				{
					printf("\nYa has cargado el archivo anteriormente\n");
				}
            break;

            case 3:
            	chequeo=controller_addPassenger(listaPasajeros);
            	if(chequeo==1)
            	{
            		printf("\nSe guardo el pasajero con exito\n");
            	}
            	else
            	{
            		printf("\nNo se pudo guardar el pasajero\n");
            	}
            break;
            case 4:
            	if(tam!=0)
            	{

            		controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo hay pasajeros ingresados\n");
            	}
            break;

            case 5:
            	if(tam!=0)
				{
					controller_removePassenger(listaPasajeros);
				}
				else
				{
					printf("\nNo hay pasajeros ingresados\n");
				}
		    break;

		    case 6:
		    	if(tam!=0)
				{
					controller_ListPassenger(listaPasajeros);
				}
				else
				{
					printf("\nNo hay pasajeros ingresados\n");
				}
		    break;

		    case 7:
		    	if(tam!=0)
				{
					controller_sortPassenger(listaPasajeros);
				}
				else
				{
					printf("\nNo hay pasajeros ingresados\n");
				}
			break;
		    case 8:
		    	if(archivoFlag==1)
				{
		    		chequeo=controller_saveAsText("data.csv",listaPasajeros);
		    		guardado=1;
		    		if(chequeo==1)
					{
						printf("\nEl archivo se guardo con exito\n");

					}
					else
					{
						printf("\nEl archivo no se guardo con exito\n");
					}
				}
				else
				{
					printf("\nTienes que cargar el archivo antes\n");
				}
			break;
		   	case 9:
		   		if(archivoFlag==1)
				{
		   			chequeo=controller_saveAsBinary("data.csv",listaPasajeros);
		   			guardado=1;
		   			if(chequeo==1)
					{
						printf("\nEl archivo se guardo con exito\n");

					}
					else
					{
						printf("\nEl archivo no se guardo con exito\n");
					}
				}
				else
				{
					printf("\nTienes que cargar el archivo antes\n");
				}

			break;
		   	case 10:
				if(guardado==1)
				{
					exit(1);
				}
				else
				{
					printf("\nTienes que guardar en el archivo antes de irte\n");
				}
			break;
        }
    }while(option != 11);
    ll_deleteLinkedList(listaPasajeros);
    return 0;
}

