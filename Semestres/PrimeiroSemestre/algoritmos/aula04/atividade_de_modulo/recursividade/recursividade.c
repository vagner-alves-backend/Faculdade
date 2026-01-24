#include <stdio.h>
#include <stdlib.h>

int fibonacci_simples(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci_simples(n - 1) + fibonacci_simples(n - 2);
    }
} 

int fibonacci_em_cauda(int n, int anterior, int atual) {
    if (n <= 0) {
        return anterior;
    } else if (n == 1) {
        return atual;
    } else {
        return fibonacci_em_cauda(n - 1, atual, atual + anterior);
    }
}

int fibonacci(int n) {
    return fibonacci_em_cauda(n, 0, 1);
}

int main() {

    int n, recursividade;
    char novoValor;
    do {

        printf("------------------------------------------------------\n");
        printf("Deseja ver qual modelo recursivo?\n[1] Simples\n[2] Em cauda\n[1/2]: ");
        scanf("%d", &recursividade);
        printf("......................................................\n");

        printf("Deseja ver qual algarismo de fibonacci? ");
        scanf("%d", &n);
        printf("------------------------------------------------------\n");

        if (recursividade == 1) {
            printf("Fibonacci com recursividade simples: %d \n", fibonacci_simples(n));
        } else if (recursividade == 2) {
            printf("Fibonacci com recursividade em cauda: %d \n", fibonacci(n));
        } else {
            printf("Escolha nao econtrada, sera considerado [2]\n");
            printf("Fibonacci com recursividade em cauda: %d \n", fibonacci(n));
        }
        printf("------------------------------------------------------\n");

        printf("Deseja ver um novo valor [S/N]? ");
        scanf(" %c", &novoValor);

        if (novoValor != 's' || novoValor != 'S' || novoValor != 'n' || novoValor != 'N') {
            printf("Parametro nao encontrado, sera considerado [N]\n");
            printf("------------------------------------------------------\n");
        }

    } while (novoValor == 's' || novoValor == 'S');

    return 0;
}