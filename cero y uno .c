#include <stdio.h>
#include <string.h>

int main() {
    char a[3]; 
    
    printf("Ingresa el valor '0' o '01': ");
    scanf("%2s", a);  

    if (strcmp(a, "0") == 0 || strcmp(a, "01") == 0) {
        printf(" %s\n", a);
    } else {
        printf("El valor no es válido\n");
    }

    return 0;
}

