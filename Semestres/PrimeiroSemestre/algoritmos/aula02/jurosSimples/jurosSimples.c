#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Eu tinha me esquecido da Variavel definitiva, Por isso refiz colocando ela como base do sistema de porcentagem...
*/
#define porcentagem 10
int main() {
    double powAt = 0;
    double decimal = 0.01 * porcentagem;
    decimal += 1;

    float valorInvestido, resultado = 0;
    int anos = 0;
    int anoAt = 1;

    printf("-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-------------------Juros Simples-----------------------\n");
    printf(".......................................................\n");

    printf("Valor a ser investido: ");
    scanf("%f", &valorInvestido);

    printf("Periodo em anos: ");
    scanf("%d", &anos);

    printf("------------------------------------------------------\n");

    for (int c = 0; c < anos; c++) {
        powAt = pow(decimal, anoAt);
        resultado = powAt * valorInvestido;
        printf("Em %d ano rendera: R$ %.2f \n", anoAt, resultado);

        anoAt++;
    }

    printf("_______________________________________________________\n");

    printf(":--------------VETOR e MATRIZ\n"); 
    printf(".......................................................\n");

    int vetor[3] = {23, 75, 59};
    int *prt_vetor;
    int matriz[2][2];

    printf("Vetor:\n");
    for (int posicao = 0; posicao < 3; posicao++) {
        printf("[%d]", vetor[posicao]);
    }

    printf("\nAltere elemento inicial:");
    scanf("%d", &vetor[0]);
    prt_vetor = &vetor[0];
    printf("elemento atualizado: %d", *prt_vetor);

    
    printf("\n");
    printf(".......................................................\n");

    printf("\nMatriz:\n");
    for (int eixoX = 0; eixoX < 2; eixoX++) {
        for (int eixoY = 0; eixoY < 2; eixoY++) {
            scanf("%d", &matriz[eixoX][eixoY]);
        }
        printf("\n");
    }

    for (int eixoX = 0; eixoX < 2; eixoX++) {
        for (int eixoY = 0; eixoY < 2; eixoY++) {
            printf("%d", matriz[eixoX][eixoY]);
        }
        printf("\n");
    }

    printf(".......................................................\n");

    printf("Endereco da memoria dos elementos:\n");
    printf("Do vetor:");
    printf("%p \n", vetor);
    printf("Da matriz:");
    printf("%p \n", matriz);

    printf("=======================================================\n");

    return 0;
}
