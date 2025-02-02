#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char num[15];
    char opcion;
    int valido;
    int i;
    printf("Gramatica\n");
    printf("EN -> DR\n");
    printf("R -> DR | 3\n");//El 3 representa el símbolo terminal de vacío
    printf("D -> 0..9\n");

    printf("Derivacion de la gramatica\n");
    printf("q0, 3, 3; q1, $\n");
    printf("q1, 3, 3; q2, EN\n");
    printf("q2, 3, EN; q2, DR\n");
    printf("q2, 3, R; q2, DR\n");
    printf("q1, 3, R; q2, 3\n");
    printf("q2, 3, D; q2, 0..9\n");
    printf("q2, 0..9, 0..9; q2, 3\n");
    printf("q2, 3, 3; q2, 3\n");
    printf("q2, 3, $; q2, 3\n");
    do {
        valido = 0;
        while (!valido) {
            printf("Ingresa un numero: ");
            scanf("%s", num);
            valido = 1;
            for (i = 0; i < strlen(num); i++) {
                if (!isdigit(num[i])) {
                    valido = 0;
                    break;
                }
            }
            if (!valido) {
                printf("Cadena no valida. Ingresa solo numeros\n");
            }
        }
        int length = strlen(num);
        const char* estados[] = {"q0", "q1", "q2", "q2", "q2", "q2", "q2", "q2", "q2", "q2", "q3"};
        const char* transiciones[] = {"(q0, 3, 3; q1, $)","(q1, 3, 3; q2, EN)","(q2, 3, EN; q2, DR)","(q2, 3, D; q2, 0..9)",
            "(q2, 3, R; q2, 0..9)", "(q2, 3, R; q2, DR)","(q2, 3, 0..9; q2, 0..9)","(q2, 3, 3; q2, D)","(q2, 3, 0..9; q2, 0..9)",
            /*"(q2, 3, 0..9; q2, 0..9)",*/"(q2, 3, R; q2, 3)","(q2, 3, $; q3, 3)"};
        int estado_actual = 0;
        printf("\nDerivacion:\n");
        printf("$, %s, %s, %s\n", num, estados[estado_actual], transiciones[estado_actual]);
        estado_actual++;
        printf("EN$, %s, %s, %s\n", num, estados[estado_actual], transiciones[estado_actual]);
        estado_actual++;
        printf("DR$, %s, %s, %s\n", num, estados[estado_actual], transiciones[estado_actual]);
        estado_actual++;
        for (i = 0; i < length; i++) {
            if (i == 0) {
                printf("%cR$, %s, %s, %s\n", num[i], num, estados[estado_actual], transiciones[3]);
            } else if (i == 1) {
                printf("DR$, %s, %s, %s\n", num + 1, estados[estado_actual], transiciones[4]);
                printf("DR$, %s, %s, %s\n", num + 1, estados[estado_actual], transiciones[5]);
                printf("%cR$, %c, %s, %s\n", num[i], num[1], estados[estado_actual], transiciones[6]);
            } else {
                printf("DR$, %s, %s, %s\n", num + i, estados[estado_actual], transiciones[7]);
                printf("DR$, %s, %s, %s\n", num + i, estados[estado_actual], transiciones[8]);
                printf("%cR$, %c, %s, %s\n", num[i], num[i], estados[estado_actual], transiciones[9]);
            }
        }
        printf("R$, 3, %s, %s\n", estados[10], transiciones[10]);
        printf("Cadena valida\n");
        printf("Quieres ingresar otro numero(s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');
    printf("Saliendo\n");
    return 0;
}
