#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int semana[7];
    printf("Crie uma ordem numerica para os dias da semana comecando de 0: \n");

    int contador = 1;
    for (int dia = 0; dia < 7; dia++) {

        switch (dia)
        {
            case 0: printf("Segunda: ");break;
            case 1: printf("Terca: ");break;
            case 2: printf("Quarta: ");break;
            case 3: printf("Quinta: ");break;
            case 4: printf("Sexta: ");break;
            case 5: printf("Sabado: ");break;
            case 6: printf("Domindo: ");break;
        }
        scanf("%d", &semana[dia]);

        for (int c = 0; c < dia; c++) {
            if (semana[dia] == semana[c]) {
                printf("Ja foi informado!\nInforme outro dia um nao presente... \n");
                switch (dia)
                {
                    case 0: printf("Segunda: ");break;
                    case 1: printf("Terca: ");break;
                    case 2: printf("Quarta: ");break;
                    case 3: printf("Quinta: ");break;
                    case 4: printf("Sexta: ");break;
                    case 5: printf("Sabado: ");break;
                    case 6: printf("Domindo: ");break;
                }
                scanf("%d", &semana[dia]);
                c = 0;
            }
        }
        contador++;
    }

    printf("...................................................\n");
    char diaSeman[7][50] = {"segunda", "terca", "quarta", "quinta", "sexta", "sabado", "domingo"};
    for (int dia = 0; dia < 7; dia++) {
        printf("%s = %d... \n", diaSeman[dia], semana[dia]);
    }

    return 0;
}
