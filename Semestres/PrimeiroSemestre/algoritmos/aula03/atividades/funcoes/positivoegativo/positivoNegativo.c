#include <stdio.h>
#include <stdlib.h>

int pN(int num) {
    if (num < 0) {
        printf("O numero %d e negativo...\n", num);
    } else {
        printf("O numero %d e positivo...\n", num);
    }
    return num;
}

int main()
{
    int valor; 
    char c;
    do {
        printf("Numero: ");
        scanf("%d", &valor);
        pN(valor);

        printf("continuar? ");
        scanf(" %c", &c);
    } while (c == 's' || c == 'S');

    return 0;
}
