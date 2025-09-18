#include <stdio.h>
#include <string.h>

int main() {
    int n; // número de alumnos a capturar
    char nombres[25]; 
    float sumaEdad, sumaCalif;

        printf("Ingrese el número de alumnos a capturar: ");
        scanf("%d", &n);
        int vcalif[n];
        int vedad[n];
        char vnombre[n];
        //Cree un arreglo 1-dimensional para guardar los datos
    for (int i = 0; i < n; i++) {
        printf("Ingrese el nombre (máx 24 caracteres): ");
        scanf("%s", &vnombre[i]);

        printf("Ingrese la edad: ");
        scanf("%d", &vedad[i]);

        printf("Ingrese la calificación: ");
        scanf("%d", &vcalif[i]);

        //Prepara la suma para promediar (se usó una ligera ayuda de internet para esta partecita)
        sumaEdad += vedad[i];
        sumaCalif += vcalif[i];
    }

    // Promedia
    float promedioEdad = sumaEdad / n;
    float promedioCalif = sumaCalif / n;

    printf("\nResultados:");
    printf("\n Promedio de edades: %.2f", promedioEdad);
    printf("\n Promedio de calificaciones: %.2f", promedioCalif);

    printf("\nNombres en orden inverso: ");
    for (int i=n; i>=0; i--) {
        printf("\n %s \n", vnombre[i]);
    }
    return 0;
}

