#include <stdlib.h>
#include <stddef.h>

void bsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)){
	int i,j;
	/*Se checa si los elementos del arreglo son enteros. */
	if(size == sizeof(int)){
        /* Se recorre el arreglo del primer elemento al ultimo. */
        for(i = 0; i < num -1; i++){
            /* Itera desde el primer elemento hasta uno antes de la variable. */
            for( j = 0; j < num - i - 1; j++){
                /* Se comparan los numeros, si el siguiente elemento
                 * es menor se realiza el intercambio de elementos. */
                if((*compar)((int*)base + j + 1, (int*)base + j) < 0){
                    int aux = *((int*)base + j + 1);
                    *((int*)base + j + 1) = *((int*)base + j);
                    *((int*)base + j) = aux;
                }
            }
        }
    /* Este caso es analogo al de arriba pero se usan doubles*/
	} else if(size == sizeof(double)){
        for(i = 0; i < num -1; i++){
            for( j = 0; j < num - i - 1; j++){
                if((*compar)((double*)base + j + 1, (double*)base + j) < 0){
                    double aux = *((double*)base + j + 1);
                    *((double*)base + j + 1) = *((double*)base + j);
                    *((double*)base + j) = aux;
                }
            }
        }
	}
}
