

#ifndef REPARACION_H_
#define REPARACION_H_

#include "Electrodomestico.h"

#define QTY_REPARACIONES 1000
#define QTY_FECHAS 1000
#define QTY_SERVICIOS 1000
#define MIN_IDREPA 1
#define MAX_IDREPA 1000
#define MIN_IDSERV 20000
#define MAX_IDSERV 200000
#define MAX_NOMBRE 51
#define MIN_AÑO_REPA 2020
#define MAX_AÑO_REPA 2050



struct{

int dia;
int mes;
int año;
int isEmpty;

} typedef Fecha;


struct {

char descripcion[MAX_DESCRIPCION];
float precio;
int id;
int isEmpty;
} typedef Servicio;


struct {
int serie;
Fecha fecha;
int idServicio;

int id;
int isEmpty;
} typedef Reparacion;


int reparacion_imprimir(Reparacion *employee);
int servicio_imprimir(Servicio *pServicio);
int reparacion_imprimirArray(Reparacion* list, int length);
int fecha_imprimirArray(Fecha *array, int length);
int servicio_imprimirArray(Servicio *array, int length);

int servicio_iniciar(Servicio *array, int length);
int reparacion_iniciar(Reparacion* list, int len);
int fecha_iniciar(Fecha *array, int length);

int reparacion_emptyIndex(Reparacion *array, int length, int* indice);
int servicio_emptyIndex(Servicio *array, int length, int *indice);
int fecha_emptyIndex(Fecha *array, int length, int *indice);
int reparacion_emptyArray(Reparacion *list, int length);
int servicio_emptyArray(Servicio *list, int length);
int fecha_emptyArray(Fecha *list, int length);

int reparacion_alta(Reparacion *array, int length, int *pId, int idServicio, int serie, Fecha fecha);
int servicio_alta(Servicio *array, int length, int *pId);
int fecha_alta(Fecha *array, int length, Fecha *pFecha);

int reparacion_buscarId(Reparacion *array, int length, int id, int* indice);
int servicio_buscarId(Servicio *array, int length, int id, int *indice);

int reparacion_modificar(Reparacion *array, int length);
int reparacion_baja(Reparacion *list, int len);
int reparacion_ordenar(Reparacion *array, int length);

int reparacion_altaForzada(Reparacion *array, int length, int *pId,char *serie, int idServicio, int fecha);
int servicio_altaForzada(Servicio *array, int length, char *descripcion, float precio, int *pId);

#endif /* PANTALLA_H_ */

