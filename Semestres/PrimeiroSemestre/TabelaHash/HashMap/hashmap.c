#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Tipos..
typedef struct {
    char nome[80];
    int numero;
}Cliente;


void start_cadastros(Cliente reg[]) {
    for (int i = 0; i < 100; i++) {
        strcpy(reg[i].nome, "vazio");
        reg[i].numero = 0;
    }
}



//pesquisar cliente...
int pesquisar_cliente(Cliente reg[], char nome[]) {
    int chave = 0;
    int chave_index = 0;
    for (char letra = 'A'; letra != toupper(nome[0]); letra++) {
        chave += 3;
    }
    chave_index = chave;

    if (strstr(reg[chave].nome, nome) != NULL) {
        return chave;
    } else {
        while (chave != 100) {
            if (strstr(reg[chave].nome, nome) != NULL) {
                return chave;
            }
            chave++;
        }
        chave = 0;
        while (chave != chave_index) {
            if (strstr(reg[chave].nome, nome) != NULL) {
                return chave;
            }
            chave++;
        }
    }



    return 404;
}




//Dados dos clientes..
Cliente dados_cliente(Cliente reg[]) {
    Cliente cliente;
    int encontrado = 0;
    do {
        printf("Nome: ");
        fgets(cliente.nome, 80, stdin);
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
        encontrado = pesquisar_cliente(reg, cliente.nome);

        if (encontrado != 404) {
            printf("O nome %s ja possui um registro..\nInforme um novo nome..\n", cliente.nome);
        }
    } while (encontrado != 404);
    

    int op = 0;
    printf("\tO numero deve conter 8 algarismos sem o dd e nao pode iniciar com 0\n");
    do {
        printf("\tNumero: ");
        scanf("%d", &cliente.numero);
        buffer();

        if (cliente.numero < 10000000 || cliente.numero > 99999999) {
            printf("\tNumero invalido, informe um numero valido..\n");
            op = 202;
        } else {
            op = 404;
        }
    } while(op != 404);


    return cliente;
}




//inserção de clientes...
void add_cliente(Cliente reg[]) {
    //char alfabeto[26][1] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    Cliente novo = dados_cliente(reg);
    char letra;
    int chave = 0;
    for (letra = 'A'; letra != toupper(novo.nome[0]); letra++) {
        chave += 3;
    }    

    if (strstr(reg[chave].nome, "vazio") == NULL) {
        while (chave != 100) {
            if (strstr(reg[chave].nome, "vazio") != NULL) {
                reg[chave] = novo;
                return;
            } 
            chave++;
        }
        chave = 0;
        while (chave != 100) {
            if (strstr(reg[chave].nome, "vazio") != NULL) {
                reg[chave] = novo;
                return;
            } 
            chave++;
        }
    } else {
        reg[chave] = novo;
    }

}



//Remover cliente...
void remove_cliente(Cliente reg[]) {
    char nome[80];
    printf("Informe o nome da pessoa que voce deseja remover..: ");
    fgets(nome, 80, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int chave = pesquisar_cliente(reg, nome);
    if (chave != 404) {
        printf("O cliente..:\n\tNome: %s\n\tNumero: %d\nFoi removido...\n", reg[chave].nome, reg[chave].numero);
        strcpy(reg[chave].nome, "vazio");
        reg[chave].numero = 0;
    } else {
        printf("\tCliente nao encontrado...\n");
    }
}





//imprimir todos os clientes...
void print_clientes(Cliente reg[]) {
        for (int i = 0; i < 100; i++) {
            if (strstr(reg[i].nome, "vazio") == NULL) {
                printf("\tNome: %s\n\tNumero: %d\n\t+-----------------------+\n", reg[i].nome, reg[i].numero);
            }
        }
}



int main() {
    system("cls");
    Cliente contas[100];
    start_cadastros(contas);

    char nome[80];
    int encontrado = 0;
    int op = 0;
    do {
        printf("+------Deseja------+\n");
        printf("1-\tadicionar\n2-\tRemover\n3-\tImprimir\n4-\tPesquisar cliente\n0-\tFinalizar..: ");
        scanf("%d", &op);
        buffer();

        system("cls");


        switch (op) {
            case 1:
                add_cliente(contas);
                break;

            case 2:
                remove_cliente(contas);
                break;

            case 3:
                print_clientes(contas);
                break;
            
            case 4:
                printf("Informe o nome da pessoa que voce deseja encontrar..: ");
                fgets(nome, 80, stdin);
                nome[strcspn(nome, "\n")] = 0;
                encontrado = pesquisar_cliente(contas, nome);

                if (encontrado != 404) {
                    printf("O registro..:\n\tNome: %s\n\tNumero: %d\nFoi encontrado..\n", contas[encontrado].nome, contas[encontrado].numero);
                } else {
                    printf("\t%s nao foi encontrado..\n", nome);
                }
                break;
        
            default:

                if (op == 0) {
                    op = 404;
                } else {
                    printf("\tParametro nao encontrado..\n");
                    printf("\tInforme um parametro valido..\n");
                }

                break;
        }
    } while (op != 404);

    return 0;
}