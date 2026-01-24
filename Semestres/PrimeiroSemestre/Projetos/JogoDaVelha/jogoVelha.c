#include <stdio.h>
#include <stdlib.h>


int jogo_velha[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int jogador = 1;
int linha, coluna;
int ganhou[2];
int velha;
char novoJogo;

void jogada();
void atualizar_tabuleiro();
void venceu();
void novaPartida();

int main() {
    system("cls");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jogo_velha[i][j] == 1) {
                printf(" x ");
            } else if (jogo_velha[i][j] == 2) {
                printf(" o ");
            } else if (jogo_velha[i][j] == 0) {
                printf(" - ");
            }
        }
        printf("\n");
    }

    jogada();
    return 0;
}

void jogada() {
    printf("linha: ");
    scanf("%d", &linha);

    while (linha > 3 || linha < 1) {
        printf("linha nao existe...\n");
        printf("linha: ");
        scanf("%d", &linha);
    }

    printf("coluna: ");
    scanf("%d", &coluna);

    while (coluna > 3 || coluna < 1) {
        printf("coluna nao existe...\n");
        printf("coluna: ");
        scanf("%d", &coluna);
    }

    atualizar_tabuleiro();
}

void atualizar_tabuleiro(){
    if (jogo_velha[linha-1][coluna-1] == 0) {
        jogo_velha[linha-1][coluna-1] = jogador;
    } else {
        printf("Posicao ja ocupada...\n");
        jogada();
    }

    system("cls");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jogo_velha[i][j] == 1) {
                printf(" x ");
            } else if (jogo_velha[i][j] == 2) {
                printf(" o ");
            } else if (jogo_velha[i][j] == 0) {
                printf(" - ");
            }
        }
        printf("\n");
    }
    venceu();
    jogador = jogador == 1 ? 2 : 1;
    jogada();

}

void venceu() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jogo_velha[i][j] == jogador) {
                ganhou[0]++;
            }
            if (jogo_velha[j][i] == jogador) {
                ganhou[1]++;
            }
            if (ganhou[0] == 3 || ganhou[1] == 3) {
                printf("venceu!!!\n");
                novaPartida();
            }
        }
        ganhou[0] = 0;
        ganhou[1] = 0;
    }
    if (jogo_velha[0][0] == jogador && jogo_velha[1][1] == jogador && jogo_velha[2][2] == jogador) {
        printf("Venceu!!!\n");
        novaPartida();
    } else if (jogo_velha[0][2] == jogador && jogo_velha[1][1] == jogador && jogo_velha[2][0] == jogador) {
        printf("Venceu!!!\n");
        novaPartida();
    }

    velha = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jogo_velha[i][j] != 0) {
                velha++;
            }
            if (velha == 9) {
                printf("Velha...\n");
                novaPartida();
            }
        }
    }
}

void novaPartida() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            jogo_velha[i][j] = 0;
        }
    }

    jogador = jogador == 2 ? 1 : 1;

    printf("Deseja jogar novamente [S/N]: ");
    scanf(" %c", &novoJogo);

    if (novoJogo == 's' || novoJogo == 'S') {
        main();
    } else if (novoJogo == 'n' || novoJogo == 'N') {
        exit(0);
    } else {
        printf("Parametro nao encontrado, sera considerado [N]...\n");
        exit(0);
    }
}