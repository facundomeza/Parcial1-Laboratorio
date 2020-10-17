/*
 ============================================================================
 Name        : PARCIAL LABORATORIO 1
 Author      : Facundo Meza
 Version     : 1.0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_inputs.h"
#include "Electrodomestico.h"
#include "Reparacion.h"

/**
 * Imprime mensaje error
 */
void mensajeError();

/**
 * Imprime mensaje de operación exitosa
 */
void mensajeExito();


int main(void) {

	Electrodomestico arrayElectro[QTY_ELECTRODOMESTICOS];

	Marca arrayMarcas[QTY_MARCAS];

	Reparacion arrayReparaciones[QTY_REPARACIONES];

	Servicio arrayServicios[QTY_SERVICIOS];

	Fecha arrayFechas[QTY_FECHAS];

	int idElectro = MIN_ID;
	int idMarca = MIN_IDMARCA;
	int idRepa = MIN_ID;
	int idServ = MIN_IDSERV;
	int opcion;
	int ret;
	int idAux;
	int indiceAux;
	int idServAux;
	int serieAux;

	Fecha fechaAux;

	electro_iniciar(arrayElectro, QTY_ELECTRODOMESTICOS);
	marca_iniciar(arrayMarcas, QTY_MARCAS);
	reparacion_iniciar(arrayReparaciones, QTY_REPARACIONES);
	servicio_iniciar(arrayServicios, QTY_SERVICIOS);
	fecha_iniciar(arrayFechas, QTY_FECHAS);

	electro_altaForzada(arrayElectro, QTY_ELECTRODOMESTICOS, &idElectro, 123,
			2005, 1001);
	electro_altaForzada(arrayElectro, QTY_ELECTRODOMESTICOS, &idElectro, 204512,
			2005, 1001);

	electro_altaForzada(arrayElectro, QTY_ELECTRODOMESTICOS, &idElectro, 200214,
			1990, 1002);

	marca_altaForzada(arrayMarcas, QTY_MARCAS, &idMarca, "Whirpool");
	marca_altaForzada(arrayMarcas, QTY_MARCAS, &idMarca, "Sony");
	marca_altaForzada(arrayMarcas, QTY_MARCAS, &idMarca, "Liliana");
	marca_altaForzada(arrayMarcas, QTY_MARCAS, &idMarca, "Gafa");
	marca_altaForzada(arrayMarcas, QTY_MARCAS, &idMarca, "Philips");

	servicio_altaForzada(arrayServicios, QTY_SERVICIOS, "Garantía", 250,
			&idServ);
	servicio_altaForzada(arrayServicios, QTY_SERVICIOS, "Mantenimiento", 500,
			&idServ);
	servicio_altaForzada(arrayServicios, QTY_SERVICIOS, "Repuestos", 400,
			&idServ);
	servicio_altaForzada(arrayServicios, QTY_SERVICIOS, "Refaccion", 600,
			&idServ);

	do {

		ret = utn_getNumero(&opcion, "Seleccione una opción: \n"
				"1- Alta Electrodomestico \n"
				"2- Modificar Electrodomestico \n"
				"3- Baja Electrodomestico \n"
				"4- Imprimir Listado Electrodomesticos \n"
				"5- Imprimir Listado Marcas \n"
				"6- Imprimir Listado Servicios \n"
				"7- Alta Reparacion \n"
				"8- Imprimir Listado Reparaciones \n"
				"9- Salir \n", "Opción no válida  \n", 1, 10, 2);

		if (ret == 0) {

			switch (opcion) {

			case 1:

				marca_imprimirArray(arrayMarcas, QTY_MARCAS);

				if (marca_validarId(arrayMarcas, QTY_MARCAS, &idAux) == 0) {

					if (electro_alta(arrayElectro, QTY_ELECTRODOMESTICOS,
							&idElectro, idAux) == 0) {
						mensajeExito();
					} else {
						mensajeError();
					}
				}

				else {

					printf("No existe el ID seleccionado \n");
				}
				break;

			case 2:

				electro_imprimirArray(arrayElectro, QTY_ELECTRODOMESTICOS);

				if (electro_modificar(arrayElectro, QTY_ELECTRODOMESTICOS)
						== 0) {

					mensajeExito();
				}

				else {

					mensajeError();
				}

				break;

			case 3:

				if (electro_baja(arrayElectro, QTY_ELECTRODOMESTICOS) == 0) {

					mensajeExito();
				}

				else {

					mensajeError();
				}
				break;

			case 4:

				electro_ordenar(arrayElectro, QTY_ELECTRODOMESTICOS);

				if (electro_imprimirArray(arrayElectro,
				QTY_ELECTRODOMESTICOS) == 0) { //

					mensajeExito();
				}

				else {

					mensajeError();
				}

				break;

			case 5:

				marca_imprimirArray(arrayMarcas, QTY_MARCAS);

				break;

			case 6:

				servicio_imprimirArray(arrayServicios, QTY_SERVICIOS);

				break;

			case 7:

				servicio_imprimirArray(arrayServicios, QTY_SERVICIOS);

				if (utn_getNumero(&idServAux, "Seleccione ID de servicio \n",
					"Ingreso Inválido \n", MIN_IDSERV, MAX_IDSERV, 2) == 0
					&& servicio_buscarId(arrayServicios, QTY_SERVICIOS,
					idServAux, &indiceAux) == 0) {

					electro_imprimirArray(arrayElectro, QTY_ELECTRODOMESTICOS);

					if (electro_validarSerie(arrayElectro,QTY_ELECTRODOMESTICOS, &serieAux) == 0) {

						if (fecha_alta(arrayFechas, QTY_FECHAS, &fechaAux)== 0
							&& reparacion_alta(arrayReparaciones, QTY_REPARACIONES,
								&idRepa, idServAux, serieAux, fechaAux)==0) {
							mensajeExito();

						} else {
							mensajeError();
						}

					}

					else {

						printf("El codigo de serie no existe \n");
					}

				} else {

					printf("El ID ingresado no existe \n");
				}

				break;

			case 8:

				if (reparacion_imprimirArray(arrayReparaciones,
				QTY_REPARACIONES) == 0) {
					mensajeExito();
				} else {
					mensajeError();
				}
				break;

			case 9:
				printf("Saliendo del programa");
			}

		} else {
			mensajeError();
		}

	} while (opcion != 10);

	return EXIT_SUCCESS;

}

void mensajeError() {

	char mensaje[] = "Se produjo un error. Se redigirá al menú \n";

	printf("%s", mensaje);

}

void mensajeExito() {

	char mensaje[] = "Operación exitosa \n";

	printf("%s", mensaje);

}

