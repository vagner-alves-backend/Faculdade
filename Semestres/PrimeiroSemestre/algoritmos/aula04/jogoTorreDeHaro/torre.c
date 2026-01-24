#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int base, peca;
int movimento = 1;

char linha1[3][10] = {"--**--", "------", "------"};
char linha2[3][10] = {"-****-", "------", "------"};
char linha3[3][10] = {"******", "------", "------"};
char pecas[3][10] = {"--**--", "-****-", "******"};
char vazio[10] = {"------"};
int receber;

char historico[9][15] = {"menor", "vazio", "vazio", "medio", "vazio", "vazio", "maior", "vazio", "vazio"};
char pecah[10];

int ondeEstaP[3] = {3, 0, 0};

void atualizarJogada();
void posicaoVazia();
void his();
void pecaHis();

void parametros_de_Peca_e_Base() {
    printf("Peca: ");
    scanf("%d", &peca);
    if (peca > 3 || peca < 1) {
        do {
            printf("Movimento inregular...\nInforme uma peca valida: ");
            scanf("%d", &peca);
        } while (peca > 3 || peca < 1);
    }

    if (peca > 1 && movimento == 1) {
        do {
            printf("Nao e possivel acessar essa peca...\nInforme outra: ");
            scanf("%d", &peca);
        } while (peca > 1);
    }

    printf("Base: ");
    scanf("%d", &base);
    if (base > 3 || base < 1) {
        do {
            printf("Base nao encontrada...\nInforme uma base valida: ");
            scanf("%d", &base);
        } while (base > 3 || base < 1);
    }

    if (movimento == 1 && base == 1) {
        do {
            printf("Nao e possivel mover uma peca para o mesmo lugar...\nInforme um movimento valido: ");
            scanf("%d", &base);
        } while (base == 1);
    }

    atualizarJogada();
}

void atualizarJogada() {
    if (movimento == 1) {
        strcpy(linha1[0], vazio);
        strcpy(linha3[base-1], pecas[0]);
        ondeEstaP[0] = 2;
        ondeEstaP[base-1] = 1;
    } else {
        if (ondeEstaP[base-1] > 0) {
            posicaoVazia();
            if (peca == 1) {
                if (ondeEstaP[base-1] == 2) {
                    strcpy(linha1[base-1], pecas[0]);
                } else if (ondeEstaP[base-1] == 1) {
                    strcpy(linha2[base-1], pecas[0]);
                }
            } 
            ondeEstaP[base-1] += 1;
        } else {
            posicaoVazia();
            strcpy(linha3[base-1], pecas[peca-1]);
            ondeEstaP[base-1] += 1;
        }
    }
    printf("%s %s %s \n%s %s %s \n%s %s %s \n", linha1[0], linha1[1], linha1[2], linha2[0], linha2[1], linha2[2], linha3[0], linha3[1], linha3[2]);
    his();
    movimento++;
    receber = base;
    printf("M: %d\n", movimento);
    parametros_de_Peca_e_Base();
}

void posicaoVazia() {
    if (ondeEstaP[receber-1] == 2) {
        strcpy(linha2[receber-1], vazio);
    } else if (ondeEstaP[receber-1] == 1) {
        strcpy(linha3[receber-1], vazio);
    } else if (ondeEstaP[receber-1] == 3) {
        strcpy(linha1[receber-1], vazio);
    }
    ondeEstaP[receber-1] -= 1;
}

void his() {
    if (movimento == 1) {
        if (base == 2) {
            strcpy(historico[0], "v");
            strcpy(historico[7], "menor");
        } else if (base == 3) {
            strcpy(historico[0], "vazio");
            strcpy(historico[8], "menor");
        }
    }

    printf("Historioco: \n%s %s %s\n%s %s %s\n%s %s %s\n", historico[0], historico[1], historico[2], historico[3], historico[4], historico[5], historico[6], historico[7], historico[8]);

}

void pecaHis(){
    if (peca == 1) {
        strcpy(pecah, "menor");
    } else if (peca == 2) {
        strcpy(pecah, "media");
    } else {
        strcpy(pecah, "maior");
    }
}

int main() {

    parametros_de_Peca_e_Base();
    return 0;
}