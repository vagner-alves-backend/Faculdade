#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int peca, base, ganhou;
int movimento = 1;
int historico[3][3] = {{1, 0, 0}, {2, 0, 0}, {3, 0, 0}};

void moverPeca();
void venceu();


int main() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (historico[i][j] == 1) {
                printf("--**-- ");
            } else if (historico[i][j] == 2) {
                printf("-****- ");
            } else if (historico[i][j] == 3) {
                printf("****** ");
            } else if (historico[i][j] == 0) {
                printf("------ ");
            }
        }
        printf("\n");
    }

    printf("--------------------------\n");
    printf("Pecas: \n1 = **\n2 = ****\n3 = ******\n");
    printf("Base: 1 2 3\n");
    printf("..........................\n");

    moverPeca();
    return 0;
}

void moverPeca() {

    printf("Peca: ");
    scanf("%d", &peca);

    while (peca > 3 || peca < 1) {
        printf("Peca nao encontrada..\nInforme uma peca existente: ");
        scanf("%d", &peca);
    }

    while (peca != 1 && movimento == 1) {
        printf("Movimento inregular...\nNao e possivel acessar uma peca sobreposta...\nInforme uma nova peca: ");
        scanf("%d", &peca);
    }

    if (peca != 1) {
        for (int i = 1; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (historico[i][j] == peca && historico[i-1][j] != 0) {
                    printf("Nao e possivel mover uma peca sobreposta...\n");
                    moverPeca();
                }
            }
        }
    }

    printf("Base: ");
    scanf("%d", &base);

    while (base > 3 || base < 1) {
        printf("Base nao encontrada..\nInforme uma base existente: ");
        scanf("%d", &base);
    }

    while (base == 1 && movimento == 1) {
        printf("Base ja esta completa...\nInforme uma nova base: ");
        scanf("%d", &base);
    }

    for (int i = 0; i < 3; i++) {
        if (historico[i][base-1] == 1 || (historico[i][base-1] == 2 && peca == 3)) {
            printf("Movimento inregular peca maior..\n");
            moverPeca();
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (historico[i][j] == peca) {
                historico[i][j] = 0;
                break;
            }
        }
    }


    for (int i = 2; i >= 0; i--) {
        if (historico[i][base-1] == 0) {
            historico[i][base-1] = peca;
            break;
        }
    }

    system("cls");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (historico[i][j] == 0) {
                printf("------ ");
            } else if (historico[i][j] == 1) {
                printf("--**-- ");
            } else if (historico[i][j] == 2) {
                printf("-****- ");
            } else if (historico[i][j] == 3) {
                printf("****** ");
            }
        }
        printf("\n");
    }

    /*
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", historico[i][j]);
        }
        printf("\n");
    }
    */

    if (movimento >= 7) {
        venceu();
    }
    movimento++;
    moverPeca();
}

void venceu() {
    if (historico[0][1] == 1 && historico[1][1] == 2 && historico[2][1] == 3) {
        ganhou = 1;
    } else if (historico[0][2] == 1 && historico[1][2] == 2 && historico[2][2] == 3) {
        ganhou = 1;
    }

    if (ganhou == 1) {

        printf("Venceu...\n");
        printf("-------------------------\n");
        ganhou = 0;
        movimento = 0;

        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                historico[i][j] = 0;
            }
        }

        historico[0][0] = 1;
        historico[1][0] = 2;
        historico[2][0] = 3;

        char continuar;
        printf("Deseja jogar novamente: [S/N]: ");
        scanf(" %c", &continuar);

        if (continuar == 's' || continuar == 'S') {
            system("cls");
            main();
        } else if (continuar == 'n' || continuar == 'N') {
            printf("Jogo finalizado...\n");
            exit(0);
        } else {
            printf("Parametro nao encontrado sera considerado [N]...\n");
            exit(0);
        }

        /*
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", historico[i][j]);
            }
            printf("\n");
        }
        */
        
    }
}
