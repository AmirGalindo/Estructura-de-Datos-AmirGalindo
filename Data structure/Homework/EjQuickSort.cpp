#include <stdio.h>
#include<stdlib.h>
#include "quick_sort.h"

/* Para repasar el concepto de algunos metodos de ordenamiento use un github que me encontre en 
internet. Adjunto a continuacion el link:
https://github.com/gbaudino/MetodosDeOrdenamiento
 */
void quick_sort(int *array, int izq, int der) {

    int i = izq;
    int j = der;
    //Este es el pivote. Para este ejercicio quise experimentar con el pivote en medio del arreglo 
    int pivot = array[(izq + der) / 2]; 

    while (i <= j) { //Este while analiza la partición 
//Todo el cuerpo de abajo es el recorrido y comparacion de los elementos del arreglo
//Recorrer desde la izquierda
        while (array[i] < pivot)
            i++;
//Recorrer desde la derecha
        while (array[j] > pivot)
            j--;
//Esto es cuando se encuentra el recorrido en el medio del arreglo 
        if (i <= j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
//Aca se hace el reordenamiento del arreglo ya ordenado 
    if (izq < j)
        quick_sort(array, izq, j);

    if (i < der)
        quick_sort(array, i, der);
}

int main() {

    int n;

    printf("Ingrese la cantidad de numeros que va a introducir:\n  ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Cantidad invalida.Introduzca al menos 1 numero \n");
        return -1;
    }

    int *a = (int *) malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Error al asignar memoria.\n");
        return -1;
    }

    printf("Introduce los %d numeros:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quick_sort(a, 0, n - 1);

    printf("\nArreglo ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    free(a);
    return 0;
}

