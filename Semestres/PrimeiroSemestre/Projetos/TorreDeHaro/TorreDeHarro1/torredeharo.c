#include <stdio.h>
#include <stdlib.h>

int historico_movimento[3][3] = {{1, 0, 0}, {2, 0, 0}, {3, 0, 0}};
int pecas, base = 0;
int movimento = 1;
char inicia;

void informeMovimento();
void moverPeca();
void venceuJogo();
void novoJogo();

int main() {
    system("cls");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (historico_movimento[i][j] == 1) {
                printf("--**-- ");
            } else if (historico_movimento[i][j] == 2) {
                printf("-****- ");
            } else if (historico_movimento[i][j] == 3) {
                printf("****** ");
            } else if (historico_movimento[i][j] == 0) {
                printf("------ ");
            }
        }
        printf("\n");
    }
    printf("1.--**--\n2.-****-\n3.******\nBase: 1 2 3\n");
    informeMovimento();

    return 0;
}

void informeMovimento() {
    printf("Pecas: ");
    scanf("%d", &pecas);

    while (pecas > 3 || pecas < 1 || (pecas != 1 && movimento == 1)) {
        printf("Movimento inregular...\nInforme uma peca valido: ");
        scanf("%d", &pecas);
    }

    if (pecas != 1) {
        for (int i = 1; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (historico_movimento[i][j] == pecas && historico_movimento[i-1][j] != 0) {
                    printf("Movimento inregular...\nInforme um novo movimento...\n");
                    informeMovimento();
                }
            }
        }
    }

    printf("Base: ");
    scanf("%d", &base);
    
    while (base > 3 || base < 1 || (base == 1 && movimento == 1)) {
        printf("Movimento inregular...\nInfome uma base valida: ");
        scanf("%d", &base);
    }

    if (pecas != 1) {
        for (int i = 0; i < 3; i++) {
            if (historico_movimento[i][base-1] == 1 || (historico_movimento[i][base-1] == 2 && pecas == 3) ) {
                printf("Peca, maior...\nInforme um movimento valido...\n");
                informeMovimento();
            }
        }
    }

    moverPeca();
}

void moverPeca() {
    //elimina a peca anterior para que ela não sejá duplicada...
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (historico_movimento[i][j] == pecas) {
                historico_movimento[i][j] = 0;
                break;
            }
        }
    }

    //coloca o valor da peca onde foi ordenado...
    for (int i = 2; i >= 0; i--) {
        if (historico_movimento[i][base-1] == 0) {
            historico_movimento[i][base-1] = pecas;
            break;
        }
    }

    system("cls");
    //exibe a matriz na tela...
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (historico_movimento[i][j] == 1) {
                printf("--**-- ");
            } else if (historico_movimento[i][j] == 2) {
                printf("-****- ");
            } else if (historico_movimento[i][j] == 3) {
                printf("****** ");
            } else if (historico_movimento[i][j] == 0) {
                printf("------ ");
            }
        }
        printf("\n");
    }

    if (movimento >= 7) {
        venceuJogo();
    }
    movimento++;
    informeMovimento();
} 

void venceuJogo() {
    if (historico_movimento[0][1] == 1 && historico_movimento[1][1] == 2 && historico_movimento[2][1] == 3) {
        printf("Venceu o jogo...\n");
        novoJogo();
    } else if (historico_movimento[0][2] == 1 && historico_movimento[1][2] == 2 && historico_movimento[2][2] == 3) {
        printf("Venceu o jogo...\n");
        novoJogo();
    }
}

void novoJogo() {
    movimento = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            historico_movimento[i][j] = 0;
        }
    }

    historico_movimento[0][0] = 1;
    historico_movimento[1][0] = 2;
    historico_movimento[2][0] = 3;

    printf("Deseja jogar novamente [S/N]? ");
    scanf(" %c", &inicia);

    if (inicia == 's' || inicia == 'S') {
        main();
    } else if (inicia != 'n' || inicia != 'N') {
        exit(0);
    } else {
        printf("Parametro nao encontrado...\nSera considerado [N]\n");
        exit(0);
    }
}
