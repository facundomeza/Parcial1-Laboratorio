

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

#define QTY_ELECTRODOMESTICOS 1000
#define QTY_MARCAS 100
#define QTY_TIPOS 2
#define MIN_AÑO 1900
#define MAX_AÑO 2050
#define MIN_ID 1
#define MAX_ID 1000
#define MIN_IDMARCA 1000
#define MAX_IDMARCA 10000000
#define MAX_NUMSERIE 2000000

#define MAX_DESCRIPCION 20


struct {

int id;
int serie;
int idMarca;
int año;

int isEmpty;
} typedef Electrodomestico;



struct {
int id;
char descripcion[MAX_DESCRIPCION];
int isEmpty;
} typedef Marca;



int electro_imprimir(Electrodomestico *electro);
int marca_imprimir(Marca *pMarca);
int electro_imprimirArray(Electrodomestico* list, int length);
int marca_imprimirArray(Marca *array, int length);

int electro_iniciar(Electrodomestico* list, int len);
int marca_iniciar(Marca *array, int length);

int electro_emptyIndex(Electrodomestico *array, int length, int* indice);
int marca_emptyIndex(Marca *array, int length, int *indice);
int electro_emptyArray(Electrodomestico *list, int length);
int marca_emptyArray(Electrodomestico *list, int length);


int electro_alta(Electrodomestico *array, int length, int *pId, int idMarca);
int marca_alta(Marca *array, int length, int *pId);

int electro_buscarId(Electrodomestico *array, int length, int id, int *resultado);
int marca_buscarId(Marca *array, int length, int id, int *indice);
int marca_validarId (Marca *array,int length,int *id);
int electro_validarSerie (Electrodomestico *array, int length,int *serie);

int electro_modificar(Electrodomestico *array, int length);
int electro_baja(Electrodomestico *list, int len);
int electro_ordenar(Electrodomestico *array, int length);


int electro_altaForzada(Electrodomestico *array, int length, int *pId, int serie,
		int año, int idMarca);
int marca_altaForzada(Marca *array, int length, int *pId, char *descripcion);

#endif /* ELECTRODOMESTICO_H_ */

