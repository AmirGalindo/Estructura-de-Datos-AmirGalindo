#include <stdio.h>

int main() {
    int n, m;
    
    printf("Ingrese n filas (con un maximo de 10): ");
    scanf("%d", &n);
    printf("Ingrese m columnas (con un maximo de 10): ");
    scanf("%d", &m);
    int matriz[n][m];
    if(n<=10 && m<=10){
	

    //Aquí llené el arreglo con números crecientes para que se pueda visualizar
    int contador = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = contador++;
        }
    }

    // Imprimi la matriz para verla con el recorrido usual
    printf("\n Matriz ingresada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Recorrido por filas
    printf("\nRecorrido por fila:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\n");

    // Recorrido por columnas
    printf("\n Recorrido por columnas:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ", matriz[j][i]);
        }
    }
    printf("\n");

    // Recorrido Diagonal
    if (n == m) {
        printf("\n Recorrido diagonal principal:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", matriz[i][i]);
        }
        printf("\n");
    } else {
        printf("\n Diagonal principal solo se recorre si n = m.\n");
    }

    return 0;
} else{
	printf("\n Ingresó un número de dimensión no válido. Intente de nuevo por favor");
}
}

