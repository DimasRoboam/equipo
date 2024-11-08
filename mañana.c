#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

void generar_cadena(char *cadena) {
    int i, num_b, num_c, num_e;
    // Generamos una subcadena que sigue (ab*c*)+ 
    cadena[0] = 'a'; // Primero la 'a' es fija
    // Determinamos aleatoriamente cuántos 'b' y 'c' habrá
    num_b = rand() % 5;  // Entre 0 y 4 'b'
    num_c = rand() % 5;  // Entre 0 y 4 'c'
    // Agregamos los 'b' y 'c' correspondientes
    for (i = 1; i <= num_b; i++) {
        cadena[i] = 'b';
    }
    for (i = num_b + 1; i <= num_b + num_c; i++) {
        cadena[i] = 'c';
    }
    // Ahora agregamos la parte de 'de*'
    int offset = num_b + num_c + 1;  // Posición después de 'ab*c*'
    cadena[offset++] = 'd';
    // Generamos aleatoriamente el número de 'e' en 'de*'
    num_e = rand() % 5;  // Entre 0 y 4 'e'
    for (i = 0; i < num_e; i++) {
        cadena[offset++] = 'e';
    }
    // Aseguramos que la cadena esté terminada
    cadena[offset] = '\0';
}
void generar_numero(char *cadena, int tipo) {
    int num_digitos, i;
    // Determinar aleatoriamente cuántos dígitos tendrá el número
    num_digitos = rand() % 8 + 1;  // Entre 1 y 8 dígitos
    // Generar el número basado en el tipo
    if (tipo == 0) {  // Número sin signo
        for (i = 0; i < num_digitos; i++) {
            cadena[i] = '0' + rand() % 10;
        }
    } else if (tipo == 1) {  // Número negativo
        cadena[0] = '-';
        for (i = 1; i <= num_digitos; i++) {
            cadena[i] = '0' + rand() % 10;
        }
    } else if (tipo == 2) {  // Número con signo positivo
        cadena[0] = '+';
        for (i = 1; i <= num_digitos; i++) {
            cadena[i] = '0' + rand() % 10;
        }
    }
    // Asegurar que la cadena esté terminada
    cadena[num_digitos + (tipo != 0 ? 1 : 0)] = '\0';
}
int main() {
    srand(time(NULL));  // Inicializa la semilla aleatoria
    int opcion;
    char a[3];  // Cadena 01|0
    
    do {
        printf("Selecciona una opcion del menu:\n");
        printf("1. 01|0\n");
        printf("2. (ab*c*)+de*\n");
        printf("3. L=(+|-)D+\n");
        printf("4. Salir\n");
        printf("Opcion:");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa el valor '0' o '01': ");
                scanf("%2s", a);

                if (strcmp(a, "0") == 0 || strcmp(a, "01") == 0) {
                    printf(" %s\n", a);
                } else {
                    printf("El valor no es valido\n");
                }
                break;
            case 2: {
                int num_cadenas;
                printf("Ingrese el numero de cadenas que desea generar: ");
                scanf("%d", &num_cadenas);

                char conjunto_cadenas[1000] = ""; 
                int i;
                for (i = 0; i < num_cadenas; i++) {
                    char cadena[100]; 
                    generar_cadena(cadena);

                    if (i > 0) {
                        strcat(conjunto_cadenas, ",");
                    }
                    strcat(conjunto_cadenas, cadena);
                }
                printf("Conjunto de cadenas generadas: %s\n", conjunto_cadenas);
                break;
            }
            case 3: {
                int num_cadenas;
                printf("Ingresa la cantidad de numeros que deseas generar: ");
                scanf("%d", &num_cadenas);

                char conjunto_numeros[1000] = "0";  // Inicializar con "0" para que sea el primer número en la salida
                int i;
                for (i = 1; i < num_cadenas; i++) {  // Empezar desde 1 para omitir el primer número que ya es 0
                    char cadena[100];  
                    int tipo = (i - 1) % 3;  
                    generar_numero(cadena, tipo);

                    strcat(conjunto_numeros, ",");  // Agregar una coma antes del número generado
                    strcat(conjunto_numeros, cadena);  // Añadir el número generado al conjunto
                }
                printf("Conjunto de numeros generados: %s\n", conjunto_numeros);
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
