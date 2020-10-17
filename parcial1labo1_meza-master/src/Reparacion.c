#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_inputs.h"
#include "Reparacion.h"
#include "Electrodomestico.h"

/**
 * Imprime todos los datos de una posicion de Reparacion
 * @param puntero a estructura Pantalla a imprimir
 * @return 0 Éxito -1 Error
 */

int reparacion_imprimir(Reparacion *pReparacion) {

	int ret = -1;

	if (pReparacion != NULL && pReparacion->isEmpty == 0) {

		printf(
				"Reparacion id %d Serie Electrodomestico: %d, Id servicio: %d Fecha: %d / %d / %d \n ",
				pReparacion->id, pReparacion->serie, pReparacion->idServicio,
				pReparacion->fecha.dia, pReparacion->fecha.mes,
				pReparacion->fecha.año);

		ret = 0;

	}
	return ret;
}

/**
 * Imprime todos los datos de una posicion de Servicio
 * @param pServicio array Servicio
 * @return 0 Éxito -1 Error
 */
int servicio_imprimir(Servicio *pServicio) {

	int ret = -1;

	if (pServicio != NULL && pServicio->isEmpty == 0) {

		printf("Servicio id %d Descripcion: %s, Precio: %.2f \n ",
				pServicio->id, pServicio->descripcion, pServicio->precio);

		ret = 0;

	}
	return ret;
}

/**
 * Imprime dia, mes y año a partir de Estructura Fecha
 * @param pFecha
 * @return 0 Éxito -1 Error
 */
int fecha_imprimir(Fecha *pFecha) {

	int ret = -1;

	if (pFecha != NULL && pFecha->isEmpty == 0) {

		printf("Fecha: %d / %d / %d \n ", pFecha->dia, pFecha->mes,
				pFecha->año);

		ret = 0;

	}
	return ret;
}

/** \brief Imprime la lista de Reparaciones con sus respectivos datos
 * \param list puntero a array de Reparacion
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
int reparacion_imprimirArray(Reparacion *array, int length) {

	int ret = -1;

	if (reparacion_emptyArray(array, length)) {

		printf("No hay valores cargados para mostrar \n");

	}

	else if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				reparacion_imprimir(&array[i]);
			}

		}

		ret = 0;
	}
	return ret;
}


/**
 *Imprime una posicion del array Fecha
 * @param array
 * @param length
 * @return
 */
int fecha_imprimirArray(Fecha *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				fecha_imprimir(&array[i]);
			}

		}

		ret = 0;
	}
	return ret;
}


/**
 * Imprime array de Servicios
 * @param array array de servicios
 * @param length largo del array
 * @return 0 Éxito -1 Error
 */
int servicio_imprimirArray(Servicio *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				servicio_imprimir(&array[i]);
			}

		}

		ret = 0;
	}
	return ret;
}

/**
 * Para indicar que todas las posiciones del array Reparacion están vacías,
 * pone la bandera (isEmpty) en TRUE en todas las posiciones
 * \param list puntero al array
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
int reparacion_iniciar(Reparacion *array, int length) {

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
 * Para indicar que todas las posiciones del array Servicio están vacías,
 * pone la bandera (isEmpty) en TRUE en todas las posiciones
 * \param list puntero al array
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
int servicio_iniciar(Servicio *array, int length) {

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
 * Para indicar que todas las posiciones del array Fecha están vacías,
 * pone la bandera (isEmpty) en TRUE en todas las posiciones
 * \param list puntero al array
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */


int fecha_iniciar(Fecha *array, int length) {

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
 * Busca un lugar vacio en el array Reparacion y lo asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param puntero indice
 * @return 0 Éxito -1 Error
 */

int reparacion_emptyIndex(Reparacion *array, int length, int *indice) {

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
 * Busca un lugar vacio en el array Servicio y lo asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param puntero indice
 * @return 0 Éxito -1 Error
 */
int servicio_emptyIndex(Servicio *array, int length, int *indice) {

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
 * Busca un lugar vacio en el array Fecha y lo asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param puntero indice
 * @return 0 Éxito -1 Error
 */
int fecha_emptyIndex(Fecha *array, int length, int *indice) {

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
 * Verifica si el array Reparacion en su totalidad está vacio
 * @param list puntero a Array
 * @param length largo del Array
 * @return 1 Verdadero (Array vacio) 0 Falso
 */

int reparacion_emptyArray(Reparacion *list, int length) {

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
 * Verifica si el array Servicio en su totalidad está vacio
 * @param list puntero a Array
 * @param length largo del Array
 * @return 1 Verdadero (Array vacio) 0 Falso
 */
int servicio_emptyArray(Servicio *list, int length) {

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
 * Verifica si el array Fecha en su totalidad está vacio
 * @param list puntero a Array
 * @param length largo del Array
 * @return 1 Verdadero (Array vacio) 0 Falso
 */
int fecha_emptyArray(Fecha *list, int length) {

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
 * Agrega una Reparacion al array de Reparaciones
 * @param list puntero a Array
 * @param len longitud del array
 * @param indice indice del Array donde se agregará
 * @param *pId puntero a contador de Id
 * @return 0 Éxito -1 Error
 */

int reparacion_alta(Reparacion *array, int length, int *pId, int idServicio,
		int serie, Fecha fecha) {

	Reparacion bufferReparacion;

	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL) {

		if (reparacion_emptyIndex(array, length, &indice) == -1) {

			printf("%s", arrayCompleto);

		}

		else {

			bufferReparacion.idServicio = idServicio;

			bufferReparacion.serie = serie;

			bufferReparacion.fecha = fecha;

			bufferReparacion.id = *pId;

			bufferReparacion.isEmpty = 0;

			array[indice] = bufferReparacion;

			(*pId)++;

			ret = 0;

		}
	}

	return ret;
}

/**
 * Agrega un Servicio al Array de Servicio
 * @param array Puntero al array
 * @param length Largo del array
 * @param pId puntero a Id (Autoincremental)
 * @return
 */
int servicio_alta(Servicio *array, int length, int *pId) {

	Servicio bufferServ;

	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL) {

		if (servicio_emptyIndex(array, length, &indice) == -1) {

			printf("%s", arrayCompleto);

		}

		else if (utn_getTexto(bufferServ.descripcion, "Ingrese descripcion \n",
				"Ingreso inválido \n", 1, MAX_DESCRIPCION, 2) == 0

				&& utn_getFloat(&bufferServ.precio, "Ingrese PRECIO\n",
						"Número inválido \n", 1, 200000, 2) == 0) {

			bufferServ.id = *pId;

			bufferServ.isEmpty = 0;

			array[indice] = bufferServ;

			(*pId)++;

			ret = 0;

		}
	}

	return ret;
}

/**
 * Agrega una Fecha al Array Fecha
 * @param array Puntero al array
 * @param length Largo del array
 * @param pFecha Puntero a Estructura Fecha (auxiliar)
 * @return
 */
int fecha_alta(Fecha *array, int length, Fecha *pFecha) {

	Fecha bufferFecha;

	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";

	int ret = -1;

	if (array != NULL && length > 0) {

		if (fecha_emptyIndex(array, length, &indice) == -1) {

			printf("%s", arrayCompleto);

		}

		else if (utn_getNumero(&bufferFecha.dia, "Ingrese dia en números \n",
				"Numero invalido \n", 1, 31, 2) == 0
				&& utn_getNumero(&bufferFecha.mes, "Ingrese mes en números \n",
						"Numero invalido \n", 1, 12, 2) == 0
				&& utn_getNumero(&bufferFecha.año, "Ingrese año (4 numeros) \n",
						"Numero invalido \n", MIN_AÑO_REPA, MAX_AÑO_REPA, 2)
						== 0)

						{

			bufferFecha.isEmpty = 0;

			array[indice] = bufferFecha;

			*pFecha = bufferFecha;

			ret = 0;

		}
	}

	return ret;
}

/**
 * Verifica si existe una posición ocupada del array Reparacion
 * que coincida con el valor del id y la asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param id id a buscar
 * @param puntero a indice
 * @return posición del array
 */
int reparacion_buscarId(Reparacion *array, int length, int id, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_IDREPA) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*indice = i;

				reparacion_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}


/**
 * Verifica si existe una posición ocupada del array Servicio
 * que coincida con el valor del id y la asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param id id a buscar
 * @param puntero a indice
 * @return posición del array
 */
int servicio_buscarId(Servicio *array, int length, int id, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_IDREPA) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*indice = i;

				servicio_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}


/**
 * Agrega un Servicio al array de Servicio con datos precargados
 * @param array puntero al array
 * @param length largo del array
 * @param descripcion descripcion Servicio
 * @param precio Precio Servicio
 * @param pId Puntero a Id (autoincremental)
 * @return
 */
int servicio_altaForzada(Servicio *array, int length, char *descripcion,
		float precio, int *pId) {

	Servicio bufferServ;

	int indice = -1;

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL && descripcion != NULL) {

		servicio_emptyIndex(array, length, &indice);

		strncpy(bufferServ.descripcion, descripcion, MAX_DESCRIPCION);

		bufferServ.precio = precio;
		bufferServ.id = *pId;
		bufferServ.isEmpty = 0;
		array[indice] = bufferServ;

		(*pId)++;

		ret = 0;

	}

	return ret;

}
