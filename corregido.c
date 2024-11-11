#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int es_cadena_valida_01(const char *cadena) {
    return strcmp(cadena, "0") == 0 || strcmp(cadena, "01") == 0;
}
// cadena (ab*c*)+de*
int es_cadena_valida_abccde(const char *cadena) {
    int i = 0;

    if (cadena[i++] != 'a') return 0;
    
    while (cadena[i] == 'b') i++;
    while (cadena[i] == 'c') i++;
    
    if (cadena[i++] != 'd') return 0;
    while (cadena[i] == 'e') i++;
    
    return cadena[i] == '\0';
}
//cadena L=(+|-)D+
int es_numero_valido(const char *cadena) {
    int i = 0;

    if (cadena[i] == '+' || cadena[i] == '-') i++;
    
    if (!isdigit(cadena[i])) return 0;

    while (isdigit(cadena[i])) i++;

    return cadena[i] == '\0';
}

int contiene_solo_letras(const char *cadena) {
    int i = 0;
    while (cadena[i]) {
        if (!isalpha(cadena[i])) return 0;
        i++;
    }
    return 1;
}

int main() {
    int opcion;
    char a[3];  // Cadena 01|0
    
    do {
        printf("Selecciona una opcion del menu:\n");
        printf("1. 01|0\n");
        printf("2. (ab*c*)+de*\n");
        printf("3. L=(+|-)D+\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa el valor '0' o '01': ");
                scanf("%2s", a);

                if (es_cadena_valida_01(a)) {
                    printf("%s es una cadena valida\n", a);
                } else {
                    printf("El valor no es valido\n");
                }
                break;
            case 2: {
                char cadena[100]; 
                printf("Ingresa una cadena que siga el patron (ab*c*)+de*: ");
                scanf("%s", cadena);

                if (contiene_solo_letras(cadena) && es_cadena_valida_abccde(cadena)) {
                    printf("La cadena '%s' es valida\n", cadena);
                } else {
                    printf("La cadena '%s' no es valida\n", cadena);
                }
                break;
            }
            case 3: {
                char cadena[100];  
                printf("Ingresa un numero con signo (+|-) o sin signo: ");
                scanf("%s", cadena);

                if (es_numero_valido(cadena)) {
                    printf("El numero '%s' es valido\n", cadena);
                } else {
                    printf("El numero '%s' no es valido\n", cadena);
                }
                break;
            }
            case 4:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción no valida. Intenta de nuevo.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
