#include <stdio.h>
#include <string.h>
#define MAX 100

void potenciaPersonalizada(char L[][MAX], int n) {
    int i;
    for ( i = 0; i < n; i++) {
        if (strcmp(L[i], "01") != 0) {
            printf("0,1");
		}else{
			 if (strcmp(L[i], "01") == 0) {
            printf("0,1");
            break;
        }
	  }
    }
}
int main() {
    char L1[MAX];
    char L[9][MAX]; 

    printf("Ingresa un conjunto para 01|0: ");
    scanf("%s", L1);

    char *token = strtok(L1, ",");
    int i = 0;
    while (token != NULL && i < 8) {
        strcpy(L[i], token);
        token = strtok(NULL, ",");
        i++;
    }
    printf("L = ");
    potenciaPersonalizada(L, i);   

    return 0;
}
