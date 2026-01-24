#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct {
    int dia, mes, ano;
}Data;

typedef struct {
    char nome[50];
    int senha;
    Data nascimento;
}Registro;

void start(Registro reg[]) {
    for (int i = 0; i < 100; i++) {
        strcpy(reg[i].nome, " ");
        reg[i].nascimento.dia = 0;
        reg[i].nascimento.mes = 0;
        reg[i].nascimento.ano = 0;
        reg[i].senha = 0;
    }
}


void inserir(Registro reg[]) {

    char nome[50];
    int dia, mes, ano, senha, valida;
    int chave;

    printf("----------------------------------\n");
    printf("Nome: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Nascimento [dd mm aaaa]: ");
    scanf("%d%d%d", &dia, &mes, &ano);
    buffer();

    do {
        printf("Senha... \n->Deve conter 6 algarismos\n->Nao pode iniciar com 0\n->Todos algarismos inteiros..: ");
        scanf("%d", &senha);
        buffer();
        printf("\n");

        if (senha < 100000 || senha > 999999) {
            printf("\tSenha invalida.. Informe uma nova senha!\n\n");
        } else {
            valida = 201;
        }
    } while (valida != 201);
    printf("----------------------------------\n");

    //metodo  de espalhamento..
    chave = senha%100;

    while (reg[chave].senha != 0 && chave != 99) {
        chave++;
    }

    if (reg[99].senha > 0 && chave == 99) {
        chave = 0;
        while (reg[chave].senha != 0 && chave != 99) {
            chave++;
        }
    }

    if (reg[chave].senha == 0) {
        strcpy(reg[chave].nome, nome);
        reg[chave].senha = senha;
        reg[chave].nascimento.dia = dia;
        reg[chave].nascimento.mes = mes;
        reg[chave].nascimento.ano = ano;
    } else {
        printf("A Lista esta cheia...\n");
    }

}

int pesquisa(Registro reg[], char nome[], int senha) {
    int chave = senha%100;
    while (strcmp(reg[chave].nome, nome) != 0 && reg[chave].senha != 0 && chave < 100) {
        chave++;
    }

    if (strcmp(reg[chave].nome, nome) != 0) {
        chave = 0;
        while (strcmp(reg[chave].nome, nome) != 0 && reg[chave].senha != 0 && chave < 100) {
            chave++;
        }
    } 

    if (strcmp(reg[chave].nome, nome) == 0) {
        return chave;
    }
    return 403;
} 

void print_alunos(Registro reg[]) {
    for (int i = 0; i < 100; i++) {
        if (reg[i].senha > 0) {
            printf("\t+--------------------+\n");
            printf("\tNome: %s\n\tNascimento: %.2d/%.2d/%d\n\tsenha: %d\n\n", reg[i].nome, reg[i].nascimento.dia, reg[i].nascimento.mes, reg[i].nascimento.ano, reg[i].senha);
            
        }
    }
    printf("\t+--------------------+\n");
    printf("----------------------------------\n");
}


int main() {
    system("cls");
    Registro cadastros[100];
    start(cadastros);

    char nome[50];
    int senha = 0;
    int busca = 0;

    int cont_registrando = 0;
    do {
        printf("+--------------------------------+\n");
        printf("\tCadastre Alunos\n");
        printf("__________________________________\n");
        printf("Deseja..:\n\t1 - Cadastrar\n\t2 - Remover\n\t3 - Pesquisar\n\t4 - Imprimir\n\t0 - Finalizar\n");
        printf("----------------------------------\n");

        printf("deseja -> ");
        scanf("%d", &cont_registrando);
        buffer();

        switch (cont_registrando)
        {
        case 1:
            inserir(cadastros);
            break;
        case 2:
            printf("Deseja remover o aluno?\n");
            printf("Nome: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("Senha: ");
            scanf("%d", &senha);
            buffer();

            busca = pesquisa(cadastros, nome, senha);

            if (busca != 403) {
                printf("O aluno..: \n");
                printf("\tNome: %s\n\tnascimento: %.2d/%.2d/%d\n\tsenha: %d\nFoi removido com sucesso!\n\n", cadastros[busca].nome, cadastros[busca].nascimento.dia, cadastros[busca].nascimento.mes, cadastros[busca].nascimento.ano, cadastros[busca].senha);
                strcpy(cadastros[busca].nome, "");
                cadastros[busca].senha = 0;
                cadastros[busca].nascimento.dia = 0;
                cadastros[busca].nascimento.mes = 0;
                cadastros[busca].nascimento.ano = 0;
                
            } else {
                printf("Aluno [%s] nao foi encontrado..\n", nome);
            }
            printf("----------------------------------\n");
            break;
        case 3:
            printf("Deseja encontra o aluno?\n");
            printf("Nome: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("Senha: ");
            scanf("%d", &senha);
            buffer();

            busca = pesquisa(cadastros, nome, senha);

            if (busca != 403) {
                printf("Registro de aluno..: \n");
                printf("\tNome: %s\n\tnascimento: %.2d/%.2d/%d\n\tsenha: %d\nFoi encontrado com sucesso!\n\n", cadastros[busca].nome, cadastros[busca].nascimento.dia, cadastros[busca].nascimento.mes, cadastros[busca].nascimento.ano, cadastros[busca].senha);
                
            } else {
                printf("Aluno [%s] nao foi encontrado..\n", nome);
            }
            printf("----------------------------------\n");
            break;
        case 4:
            print_alunos(cadastros);
            break;
        case 0:
            cont_registrando = 403;
            break;
        default:
            if (cont_registrando < 0 || cont_registrando > 3) {
                printf("Parametro nao encontrado..\n");
                cont_registrando = 403;
            }
            break;
        }
        system("pause");
        system("cls");
        
    } while (cont_registrando != 403);

    return 0;
}