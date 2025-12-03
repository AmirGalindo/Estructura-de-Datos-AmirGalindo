#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Este codigo profe, uff, esto fue un reto enorme para i. Tuve que recurrir a ayuda externa 
E incluso a un leve uso de IA para solucionar miles de errores de compilacion. Y de ayuda externa tuve que 
recurrir a consultar a un amigo mio ya egresado de mac. Ahora si entremos al codigo en sí 
*/
//En esta parte hice una suerte de replica de sus stack y list.h, solo que al introducirlos se me 
//corrompia el winrar, si me puede añadir una explicacion de porque sucede eso se lo agradeceria mucho 
typedef struct Node { char data; struct Node* next; } Node;
typedef struct Stack { Node* top; } Stack;
Stack* crearStack() { Stack* s = (Stack*)malloc(sizeof(Stack)); s->top = NULL; return s; }
void push(Stack* s, char dato) { Node* n = (Node*)malloc(sizeof(Node)); n->data = dato; n->next = s->top; s->top = n; }
char pop(Stack* s) { if(s->top==NULL) return 0; Node* t=s->top; char d=t->data; s->top=t->next; free(t); return d; }
char peek(Stack* s) { if(s->top==NULL) return 0; return s->top->data; }
int empty(Stack* s) { return s->top == NULL; }


int peso(char op) { //Funcion peso, esto determina que peso tiene cada operador, el corazon del codigo 
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infijaAPostfija(char entrada[], char salida[]) {
    Stack *pila = crearStack();
    int largo = strlen(entrada);
    int k = 0; // Contador para el resultado final 
    
    
    for (int i = 0; i < largo; i++) { //Aqui hice un recorrido para ver la expresion
        char c = entrada[i];

        // Aca requeri un poco de ayuda, supuestamente esto hace que si hay un operador se mande directo al 
        //resultado final 
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            salida[k++] = c;
        }
        // Si es un ( se hace push, lo mismo se hace abajo con )
        else if (c == '(') {
            push(pila, c);
        }
        else if (c == ')') {
            while (!empty(pila) && peek(pila) != '(') {
                salida[k++] = pop(pila);
            }
            if (!empty(pila) && peek(pila) == '(') {
                pop(pila); // Desapilar el '('
            }
        }
        
        else {
            // Esto ordenará el resultado final ya incluyendo el peso de los operacores
            while (!empty(pila) && peek(pila) != '(' && peso(peek(pila)) >= peso(c)) {
                salida[k++] = pop(pila);
            }
            push(pila, c); 
        }
    }

    // Aqui termina de vaciar el stack
    while (!empty(pila)) {
        salida[k++] = pop(pila);
    }
    
    salida[k] = '\0'; //Vaciar el arreglo que contenia la cadena de la operacion en inorden
}

int main() {
    //El codigo ya es una locura asi que me fui a la sencilla con variables de arreglos estaticos
    char entrada[80];
    char invertida[80]; //Variable auxiliar para la prefija
    char salida[80];
    char resultado_postfijo[80];
    char resultado_preorden[80];
    
    printf("Introduzca la operacion en inorden: ");
    gets(entrada); 

    // Obtiene informacion de tamaño para invertir la cadena
    int largo = strlen(entrada);
    int j = 0;
    
    // Inversion de la cadena para facilitar preorden 
    for(int i = largo - 1; i >= 0; i--) {
        invertida[j] = entrada[i];
        j++;
    }
    invertida[j] = '\0'; //Vaciar cadena

    // Porque volteamos la cadena hay que volver a voltear los parentesis para que queden bien
    for(int i = 0; i < largo; i++) {
        if(invertida[i] == '(') {
            invertida[i] = ')';
        } else if(invertida[i] == ')') {
            invertida[i] = '(';
        }
    }

    //Basado en su stack.h
    Stack *pila = crearStack();
    int k = 0; // contador auxiliar
    
    printf("\nProcesando...\n");

    for(int i = 0; i < largo; i++) {
        char c = invertida[i];

        // Si es letra o numero de la operacion no hara cambios y lo mandara asi a la salida 
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            salida[k] = c;
            k++;
        }
        else if(c == '(') {
            push(pila, c);
        }
        else if(c == ')') {
            //Buscar el parentesis de apertura
            while(!empty(pila) && peek(pila) != '(') {
                char temp = pop(pila);
                salida[k] = temp;
                k++;
                printf("Se realizo pop con : %c \n", temp);
            }
            //Esto borra del resultado final los parentesis
            if(!empty(pila)) {
                pop(pila); 
            }
        }
        else {
            while(!empty(pila) && peek(pila) != '(' && peso(peek(pila)) >= peso(c)) {
                char temp = pop(pila);
                salida[k] = temp;
                k++;
                printf("Se hizo pop con : %c \n", temp);
            }
            push(pila, c);
        }
    }

    //Vacia el stack, por si queda algo despues de los operadores nada mas lo sava
    while(!empty(pila)) {
        char temp = pop(pila);
        salida[k] = temp;
        k++;
        printf("Se realizo un ultimo pop en: %c (stack vacio)\n", temp); //Si este es el pop final se vacia el stack
    }
    salida[k] = '\0';

    //Se hizo una cosa y ahora hay que "voltearla" poara obtner el preorden
    j = 0;
    int largo_salida = strlen(salida);
    for(int i = largo_salida - 1; i >= 0; i--) {
        resultado_preorden[j] = salida[i];
        j++;
    }
    resultado_preorden[j] = '\0';
    
    infijaAPostfija(entrada, resultado_postfijo);
    
    printf("Resultado Preorden: %s\n", resultado_preorden);
    
printf("Resultado Postorden: %s\n", resultado_postfijo); //como tddo lo anterior ya se hizo, solo volvi a invocar la funcion del postorden
    
	// Pausa para que el ejecutable no se cierre de golpe 
	printf("\n Teclee enter para terminar \n ");
	getch();
    return 0;
}
