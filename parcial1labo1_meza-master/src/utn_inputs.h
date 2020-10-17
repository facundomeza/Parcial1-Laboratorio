
#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_

/**
 * Pide y obtiene un número entero positvo o negativo
 * @param pResultado puntero a direccion de memoria donde se guardará el número
 * @param mensaje Mensaje para pedir el número
 * @param mensajeError Mensaje para indicar número inválido
 * @param minimo Número minimo permitido
 * @param maximo Número máximo permitido
 * @param reintentos cantidad de reintentos
 * @return 0 Éxito -1 Error
 */

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * Pide y obtiene un número flotante positvo o negativo
 * @param pResultado puntero a direccion de memoria donde se guardará el flotante
 * @param mensaje Mensaje para pedir el número
 * @param mensajeError Mensaje para indicar número inválido
 * @param minimo Número minimo permitido
 * @param maximo Número máximo permitido
 * @param reintentos cantidad de reintentos
 * @return 0 Éxito -1 Error
 */

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
 * Pide y obtiene un número negativo entero
 * @param pResultado puntero a direccion de memoria donde se guardará el numero
 * @param mensaje Mensaje para pedir el número
 * @param mensajeError Mensaje para indicar número inválido
 * @param minimo Número minimo permitido
 * @param maximo Número máximo permitido
 * @param reintentos cantidad de reintentos
 * @return 0 Éxito -1 Error
 */
int utn_getNegativo(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);


/**
 * Pide y obtiene un nombre o apellido, pudiendo ser dos palabras y una primer Mayúscula en cada una
 * @param pResultado puntero a direccion de memoria donde se guardará el nombre
 * @param mensaje Mensaje para pedir el nombre
 * @param mensajeError Mensaje para indicar nombre inválido
 * @param reintentos cantidad de reintentos
 * @return 0 Éxito -1 Error
 */

int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError,int reintentos);



int utn_getAlfanumerica(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos);

int utn_getDni(char *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo,
		int reintentos);

int utn_getChar(char *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);


int utn_getTexto(char *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);

#endif /* UTN_INPUTS_H_ */
