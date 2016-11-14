/*Incluye las funciones de b_sort.c y arreglos_random.c*/
#include "b_sort.h"
#include "arreglos_random.h"

/*Declara las funciones que vamos a ocupar*/
// función que compara dos enteros
int cmp_int(const void *a, const void *b);
// función que compara dos doubles
int cmp_double(const void *a, const void *b);
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num);
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num);


int main()
{
    // Se inicializan 2 arreglos, uno de ints y otro de doubles
    int *arr1 = arreglo_int(20, 0, 10);
    double *arr2 = arreglo_double(20, 0, 10);

    // Se imprime ordena e imprime el primer arreglo
    imprime_int(arr1, 20);
    bsort(arr1, 20, sizeof(int), &cmp_int);
    imprime_int(arr1, 20);

    // Se imprime ordena e imprime el segundo arreglo
    imprime_double(arr2, 20);
    bsort(arr2, 20, sizeof(double), &cmp_double);
    imprime_double(arr2, 20);

    // Se libera la memoria que ocupan los arreglos ordenados
    free(arr1);
    free(arr2);

    return 0;
}
/* Funcion que compara dos numeros enteros.
 * Si son iguales devuelve un cero, si el primer numero es mayor
 * que el segundo devuelve un 1 y -1 en caso contrario.*/
int cmp_int(const void *a, const void *b)
{
    int comparacion = 0;
    int num1 = *((int*)a);
    int num2 = *((int*)b);

    if(num1 == num2){
        return comparacion;
    }

    if(num1 > num2){
        comparacion = 1;
    } else {
        comparacion = -1;
    }

    return comparacion;
}

/* Funcion que compara dos numeros reales.
 * Si son iguales devuelve un cero, si el primer numero es mayor
 * que el segundo devuelve un 1 y -1 en caso contrario.*/
int cmp_double(const void *a, const void *b)
{
    int comparacion = 0;
    double num1 = *((double*)a);
    double num2 = *((double*)b);

    if(num1 == num2){
        return comparacion;
    }

    if(num1 > num2){
        comparacion = 1;
    } else {
        comparacion = -1;
    }

    return comparacion;
}

/* Funcion que imprime un arreglo de enteros
 * con el formato: [ e1 e2 ... en ] */
void imprime_int(int *arreglo, size_t num)
{
    int i;
    printf("[ ");
    for(i= 0; i < num; i++){
        printf("%d%s", arreglo[i], " ");
    }
    printf("]\n");
}

/* Funcion que imprime un arreglo de doubles
 * con el formato: [ e1 e2 ... en ] */
void imprime_double(double *arreglo, size_t num)
{
    int i;
    printf("[ ");
    for(i= 0; i < num; i++){
        printf("%.5f%s", arreglo[i], " ");
    }
    printf("]\n");
}
