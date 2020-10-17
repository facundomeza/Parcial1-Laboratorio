#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Electrodomestico.h"
#include "utn_inputs.h"



/**
 * Imprime todos los datos de una Electrodomestico
 * @param puntero a estructura Electrodomestico a imprimir
 * @return 0 Éxito -1 Error
 */

int electro_imprimir(Electrodomestico *pElectro) {

	int ret = -1;

	if (pElectro != NULL && pElectro->isEmpty == 0) {

		printf("Electrodomestico id %d Serie: %d, año: %d Id marca: %d\n",
				pElectro->id, pElectro->serie, pElectro->año, pElectro->idMarca);

		ret = 0;

	}
	return ret;
}


/**
 * Imprime todos los datos de una Marca
 * @param pMarca Puntero a array Marca
 * @return 0 Éxito -1 Error
 */

int marca_imprimir(Marca *pMarca) {

	int ret = -1;

	if (pMarca != NULL && pMarca->isEmpty == 0) {

		printf("Marca id %d: %s\n",
				pMarca->id, pMarca->descripcion);

		ret = 0;

	}
	return ret;
}



/** \brief Imprime la lista de Electrodomesticos con sus respectivos datos
 * \param list puntero a array de Electrodomesticos
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
int electro_imprimirArray(Electrodomestico *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				electro_imprimir(&array[i]);
			}

		}

		ret = 0;
	}
	return ret;
}

/**
 * Imprime la lista de Marcas con sus datos
 * @param array puntero a array Marcas
 * @param length largo del array
 * @return 0 Éxito -1 Error
 */
int marca_imprimirArray(Marca *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				marca_imprimir(&array[i]);
			}

		}

		ret = 0;
	}
	return ret;
}



/**
 * Para indicar que todas las posiciones del array Electrodomestico están vacías,
 * pone la bandera (isEmpty) en TRUE en todas las posiciones
 * \param list puntero al array
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
int electro_iniciar(Electrodomestico *array, int length) {

	int ret = -1;
	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {
			array[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}


/**
 * Pone la bandera Is Empty en 1 en todas las posiciones
 * del array Marca
 * @param array
 * @param length
 * @return
 */

int marca_iniciar(Marca *array, int length) {

	int ret = -1;
	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {
			array[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}

/**
 * Busca un lugar vacio en el array de Electrdomesticos y lo asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param puntero indice
 * @return 0 Éxito -1 Error
 */

int electro_emptyIndex(Electrodomestico *array, int length, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 1) {

				ret = 0;
				*indice = i;
				break;

			}
		}
	}

	return ret;
}

/**
 * Busca un lugar vacio en el array de Marcas
 * y lo asigna a puntero Indice
 * @param array puntero a array de marcas
 * @param length largo del array
 * @param indice puntero a indice
 * @return
 */
int marca_emptyIndex(Marca *array, int length, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 1) {

				ret = 0;
				*indice = i;
				break;

			}
		}
	}

	return ret;
}


/**
 * Verifica si el array Electrodomesticos en su totalidad está vacio
 * @param list puntero a Array
 * @param length largo del Array
 * @return 1 Verdadero (Array vacio) 0 Falso
 */

int electro_emptyArray(Electrodomestico *list, int length) {

	int ret = 1; // TRUE

	if (list != NULL && length > 0) {
		for (int i = 0; i < length; i++) {

			if (list[i].isEmpty == 0) {

				ret = 0;
				break;
			}
		}
	}

	return ret;
}

/**
 * Verifica si el array Marca en su totalidad esta vacio
 * @param list puntero a Array de Marca
 * @param length largo del array
 * @return 1 True 0 Falso
 */
int marca_emptyArray(Electrodomestico *list, int length) {

	int ret = 1; // TRUE

	if (list != NULL && length > 0) {
		for (int i = 0; i < length; i++) {

			if (list[i].isEmpty == 0) {

				ret = 0;
				break;
			}
		}
	}

	return ret;
}

/**
 * Agrega una Electrodomestico al array de Electrodomesticos
 * @param list puntero a Array
 * @param len longitud del array
 * @param indice indice del Array donde se agregará
 * @param *pId puntero a contador de Id
 * @return 0 Éxito -1 Error
 */

int electro_alta(Electrodomestico *array, int length, int *pId, int idMarca) {

	Electrodomestico bufferElectro;

	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL) {

		if (electro_emptyIndex(array, length, &indice) == -1) {

			printf("%s", arrayCompleto);

		}

		else if (utn_getNumero(&bufferElectro.serie, "Ingrese codigo de serie \n","Ingreso inválido \n",1,MAX_NUMSERIE,2)==0

				        && utn_getNumero(&bufferElectro.año,
						"Ingrese número correspondiente al año \n",
						"Número inválido \n", MIN_AÑO, MAX_AÑO, 2) == 0) {

			bufferElectro.idMarca = idMarca;

			bufferElectro.id = *pId;

			bufferElectro.isEmpty = 0;

			array[indice] = bufferElectro;

			(*pId)++;

			ret = 0;

		}
	}

	return ret;
}

/**
 * Agrega una Marca al Array de Marcas
 * @param array
 * @param length
 * @param pId
 * @return
 */
int marca_alta(Marca *array, int length, int *pId) {

	Marca bufferMarca;

	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL) {

		if (marca_emptyIndex(array, length, &indice) == -1) {

			printf("%s", arrayCompleto);

		}

		else if (utn_getTexto(bufferMarca.descripcion,
				"Ingrese descripcion", "Ingreso invalido",1,MAX_DESCRIPCION,2)==0) {

			bufferMarca.id = *pId;

			bufferMarca.isEmpty = 0;

			array[indice] = bufferMarca
					;

			(*pId)++;

			ret = 0;

		}
	}

	return ret;
}

/**
 * Verifica si existe una posición ocupada del array Electrdomesticos
 * que coincida con el valor del id y la asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param id id a buscar
 * @param puntero a indice
 * @return posición del array
 */
int electro_buscarId(Electrodomestico *array, int length, int id, int *resultado) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_ID) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*resultado = i;

				electro_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}


/**
 * Verifica si el numero de serie ingresado se encuentra
 * en alguna posicion del array Electrodomesticos
 * @param array puntero a Array de electrodomesticos
 * @param length Largo del array
 * @param serie Puntero a Numero de serie encontrado
 * @return 0 Éxito -1 Error
 */
int electro_validarSerie (Electrodomestico *array, int length,int *serie){

	int ret = -1;

	int serieAux;

	utn_getNumero(&serieAux, "Ingrese el codigo de serie correspondiente al Electrodomestico \n","Ingreso inválido \n",1,2000000,2);

	for (int i=0; i < length; i++){


		if (array[i].serie == serieAux && array[i].isEmpty==0){

			ret = 0;
			*serie = serieAux;

		}
	}





	return ret;



}


/**
 * Busca un id en el Array de Marca
 * y lo devuelve mediante puntero
 * @param array puntero a array marca
 * @param length largo del array
 * @param id puntero a Id encontrado
 * @return 0 Éxito -1 Error
 */
int marca_validarId (Marca *array,int length,int *id){

	int ret = -1;

	int idAux;
	int indice;


	if (utn_getNumero(&idAux, "Ingrese el ID de la Marca \n","Ingreso Invalido \n",MIN_IDMARCA,MAX_IDMARCA,2)==0){


		if (marca_buscarId(array, length,idAux,&indice)==0){

			ret = 0;
			*id = idAux;

		}

	}


	return ret;


}


/**
 * Busca un id en el array de Marca y devuelve la posicion
 * donde se encuentra
 * @param array
 * @param length
 * @param id
 * @param indice
 * @return
 */
int marca_buscarId(Marca *array, int length, int id, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_ID) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*indice = i;

				marca_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}

/**
 * Actualiza uno de los datos del Electrodomestico
 * en el array, verificando si existe su id
 * @param list puntero al array
 * @param len longitud del array
 * @return 0 Éxito -1 Error
 */
int electro_modificar(Electrodomestico *array, int length) {

	int ret = -1;
	int indice = -1;
	int opcion;
	char idError[] = "No existe el Id seleccionado \n";

    int serie;
	int año;
	int id;

	if (electro_emptyArray(array, length)) {

		printf("No se registra ninguna carga \n");
	}

	else if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id del Electrodomestico a modificar \n",
			"Número inválido \n", 0, 1000, 2) == 0) {

		     electro_buscarId(array, QTY_ELECTRODOMESTICOS, id, &indice);

		     if (indice != -1 && utn_getNumero(&opcion,
				"Ingrese el número correspondiente a la opción: "
								"\n 1-Modificar SERIE "
								"\n 2-Modificar AÑO \n",
								"Opción inválida \n", 1, 2, 2) == 0) {

			switch (opcion) {

			case 1:

				if (utn_getNumero(&serie,"Ingrese nuevo número de Serie \n","Ingreso inválido \n",1,MAX_NUMSERIE,2)==0) {

					array[indice].serie = serie;

					ret = 0;
				}

				break;

			case 2:

				if (utn_getNumero(&año, "Ingrese AÑO\n",
						"Número fuera de rango", MIN_AÑO, MAX_AÑO, 2)
						== 0) {

					array[indice].año = año;

					ret = 0;
				}

				break;
			}
		}

		else if (indice == -1) {
			(printf("%s", idError));
		}
	}

	return ret;
}

/**
 * Pide un Electrodomestico del array a eliminar por id,
 * verifica que existe y pone la bandera Is Empty en 1
 * @param list puntero al array
 * @param len largo del array
 * @return
 */

int electro_baja(Electrodomestico *array, int length) {

	int option = 2; // Cancelar

	int ret = -1;

	int id;

	int indice = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "No existe el id seleccionado \n";

	if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id a buscar \n",
					"Número inválido \n", MIN_ID, MAX_ID, 2) == 0) {

		electro_buscarId(array, QTY_ELECTRODOMESTICOS, id, &indice);

		if (indice != -1
				&& utn_getNumero(&option, "Seleccione: 1 para borrar - "
						"2 para cancelar operación \n", "Opción inválida \n", 1,
						2, 2) == 0 && option == 1) {

			array[indice].isEmpty = 1;

			ret = 0;

		}

		else if (indice == -1) {
			printf("%s", idError);
		}

		else if (option != 1) {

			printf("%s", cancel);
		}

	}
	return ret;
}

/**
 * Ordena los elementos del array Electrodomestico
 * de manera ascendente en base a Año y Serie
 * @param array puntero a array
 * @param largo del array
 * @return 0 Éxito -1 Error
 *
 */


int electro_ordenar(Electrodomestico *array, int length) {

	int ret = -1;
	int flagSwap;
	Electrodomestico buffer;

		do {

			flagSwap = 0;

			for (int i = 0; i < length - 1; i++) {

					if (
							array[i].año > array[i + 1].año
							|| (array[i].año == array[i + 1].año
							&& array[i].serie > array[i + 1].serie)) {

						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i + 1];
						array[i + 1] = buffer;
					}
			}

			length--;

		} while (flagSwap == 1);

		ret = 0;


	return ret;
}


/**
 * Inserta un Electrodomestico en el array Electrodomesticos
 * con los datos ya cargados
 * @param array Puntero al array
 * @param length Largo del array
 * @param pId Puntero a id
 * @param nombre Datos nombre Pantalla
 * @param direccion Datos direccion Pantalla
 * @param precio Datos precio Pantalla
 * @param tipo Datos tipo de Pantalla
 * @return 0 Éxito -1 Error
 */

int electro_altaForzada(Electrodomestico *array, int length, int *pId, int serie,
		int año, int idMarca) {

	Electrodomestico bufferElectro;

	int indice = -1;

	int ret = -1;

	if (array != NULL && length > 0&& pId != NULL) {

		electro_emptyIndex(array, length, &indice);

		bufferElectro.serie = serie;
		bufferElectro.año = año;

		bufferElectro.id = *pId;

		bufferElectro.idMarca = idMarca;

		bufferElectro.isEmpty = 0;

		array[indice] = bufferElectro;

		(*pId)++;

		ret = 0;

	}

	return ret;

}

/**
 * Introduce una Marca en el array de Marcas con los datos ya cargados
 * @param array Puntero a array de marcas
 * @param length Largo del array
 * @param pId Puntero a Id (Autoincremental)
 * @param descripcion Descripcion de la Marca
 * @return
 */
int marca_altaForzada(Marca *array, int length, int *pId, char *descripcion) {

	Marca bufferMarca;

	int indice = -1;

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL && descripcion!=NULL) {

		marca_emptyIndex(array, length, &indice);

		strncpy(bufferMarca.descripcion, descripcion, MAX_DESCRIPCION);

		bufferMarca.id = *pId;
		bufferMarca.isEmpty = 0;
		array[indice] = bufferMarca;

		(*pId)++;

		ret = 0;

	}

	return ret;

}


