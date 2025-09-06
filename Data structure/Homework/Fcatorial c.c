#include <string.h>
#include <stdio.h>
#include <stdlib.h>

facTail(n, a){
    if(n < 0){
        return 0;
    }
        
    else if (n == 0){
        return 1;
    }
        
    else if (n == 1){
        return a;
    }
        
    else {
        return facTail(n-1,n*a);
    }
        
}
    
int main(){
    int n=1, a;
    printf("Introduzca un numero \n");
    scanf("%d", &a);
    printf("Introduzca otro número \n");
    scanf("%d", &a);
    printf("%d",facTail(n,a));
    return 1;
}
