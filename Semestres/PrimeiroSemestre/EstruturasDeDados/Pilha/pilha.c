#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n1, n2, resp;
    char operador;
}Calc;

typedef struct no {
    Calc calculadora;
    struct no *next;
}No;

typedef struct {
    No *begin;
}List;

void start_list(List *list) {
    list->begin = NULL;
}

void buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Calc add_number() {
    Calc calculo;
   
    printf("---Calculando---\n");
    printf("algarismo 1..: ");
    scanf("%d", &calculo.n1);
    buffer();

    int continue_ = 0;
    do {
        char op;
        printf("Esvolha um operador [+, -, x, :]..: ");
        scanf("%c", &op);
        buffer();

        if (op == 'X') {
            op = 'x';
        }
        if (op != '+' && op != '-' && op != 'x' && op != ':') {
            printf("operador inregular.. \nInforme um operador valido.\n");
            continue_ = 1;
        } else {
            calculo.operador = op;
            continue_ = 0;
        }
  
    } while (continue_ != 0);
    


    printf("algarismo 2..: ");
    scanf("%d", &calculo.n2);
    buffer();

    if (calculo.operador == '+') {
        calculo.resp = calculo.n1 + calculo.n2;
    } else if (calculo.operador == '-') {
        calculo.resp = calculo.n1 - calculo.n2;
    } else if (calculo.operador == 'x' || calculo.operador == 'X') {
        calculo.resp = calculo.n1 * calculo.n2;
    } else {
        calculo.resp = calculo.n1 / calculo.n2;
    }

    printf("[%d %c %d = %d] \n", calculo.n1, calculo.operador, calculo.n2, calculo.resp);

    return calculo;
}

void push(List *list) {
    No *newElement = malloc(sizeof(No));
    newElement->calculadora = add_number();

    if (list->begin == NULL) {
        newElement->next = NULL;
        list->begin = newElement;
        return;
    }
    newElement->next = list->begin;
    list->begin = newElement;
}

No* pop(List *list) {
    No *remove = NULL;
    if (list->begin != NULL) {
        remove  = list->begin;
        list->begin = remove->next;
    }
    return remove;
}

void print_list(List *list) {
    if (list->begin == NULL) {
        printf("Nao a elementos na pilha..\n");
        return;
    }
    No *aux = list->begin;
    while (aux != NULL) {
        printf("[%d %c %d = %d] ", aux->calculadora.n1, aux->calculadora.operador, aux->calculadora.n2, aux->calculadora.resp);
        printf("\n");
        aux = aux->next;
    }
}

int main() {
    system("cls");

    List list;
    start_list(&list);

    No *remove = NULL;

    int op = 0;
    do {
        printf("---Acoes---\n");
        printf("[1] Adicione\n[2] Remover\n[3] Imprimir\n[4] Finalizar..: ");
        scanf("%d", &op);
        system("cls");

        if (op < 0 || op > 4) {
            printf("Parametro nao encontrado...\n");
            op = 0;
        }

        switch (op)
        {
        case 1:
            push(&list);
            break;
        case 2:
            remove = pop(&list);
            if (remove != NULL) {
                printf("O calculo removido [anterior] e:\n [%d %c %d = %d]\nS", remove->calculadora.n1, remove->calculadora.operador, remove->calculadora.n2, remove->calculadora.resp);
            } else {
                printf("A pilha esta vazia..\n");
            }
            free(remove);

            break;
        case 3:
            print_list(&list);
            break;
        
        default:
            break;
        }
    } while (op != 0);

    return 0;
}
