#include <stdio.h>
#include "counting_sort.h"
#include <stdlib.h>
// Este codigo es de counting sort. Lo elegí porque fue más o menos mi metodo favorito

int counting_sort(int *array, int size, int max_value) {
//Corta el codigo si se mete un tamaño de arreglo incorrecto
    if (array == NULL || size <= 0 || max_value < 0)
        return -1;

//Este es el arreglo auxiliar donde se hacen los cálculos de cómo se ardenarán los datos
//Los calculos de restas que vimos e clase, en otras palabras
    int *count = (int *) malloc((max_value + 1) * sizeof(int));
    if (count == NULL)
        return -1;

    for (int i = 0; i <= max_value; i++)
        count[i] = 0;
//Cuenta cuantas veces se repite un numero si es el caso
    for (int i = 0; i < size; i++)
        count[array[i]]++;
//Con ayuda del arreglo count de arriba se hace el ordenamiento
    int index = 0; //Variale auxiliar para el ordenamiento
    for (int i = 0; i <= max_value; i++) {
        while (count[i] > 0) {
            array[index++] = i;
            count[i]--;
        }
    }

    free(count);
    return 0;
}

int main() {

    int n, maxv;

    printf("Ingrese la cantidad de numeros que quiera ordenar: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Cantidad invalida. Debe de querer ingresar al menos un numero\n");
        return -1;
    }

    int *a = (int *) malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Error al asignar memoria.\n");
        return -1;
    }

    printf("Introduce los %d numeros:\n", n);
    maxv = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > maxv)
            maxv = a[i];
    }

    if (counting_sort(a, n, maxv) != 0) {
        printf("Error en counting sort.\n");
        free(a);
        return -1;
    }

    printf("\nArreglo ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    free(a);
    return 0;
}
