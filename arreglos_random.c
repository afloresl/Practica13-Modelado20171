#include <stdio.h>
/* Para poder generar los numeros del arreglo*/
#include <time.h>
#include <stdlib.h>

int* arreglo_int(size_t num, int min, int max){
    /* Nos regresara el tiempo (depende de la fecha actual)
     * para poder generar los numeros aleatorios. */
	srand(time(NULL));
	/* Calloc nos proporcionara memoria limpia. */
	int *arreglo = (int*) calloc(num, sizeof(int));
	int i;
	for(i = 0; i < num; i++)
        /* Llenando el arreglo con numeros aleatorios. */
		arreglo[i] = (rand() % (max + 1 - min)) + min;
	return arreglo;
}

double* arreglo_double(size_t num, double min, double max)
{
    /* Nos regresara el tiempo (depende de la fecha actual)
     * para poder generar los numeros aleatorios. */
	srand(time(NULL));
	/* Apuntador de double. Calloc nos proporcionara memoria limpia. */
	double *arreglo = (double*) calloc(num, sizeof(double));
	int i;
	for(i = 0; i < num; i++){
	    /* Generamos los numeros tambien es necesario
	     * el rango entre los que se encuentran dichos numeros. */
        double rango = (max - min);
    	double aux = RAND_MAX / rango;
        double dato = min + (rand() / aux);
		arreglo[i] = dato;
	}
	return arreglo;
}
