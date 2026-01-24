#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct no {
    int number;
    struct no *previus;
    struct no *next;
}No;

typedef struct {
    No *begin;
    No *end;
    int size;
}List;

void start_list(List *list) {
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;
}

int number_info() {
    int n = 0;
    printf("---Informe---\n");
    printf("Number..: ");
    scanf("%d", &n);
    buffer();

    return n;
}

void add_number_begin(List *list) {
    No *new = malloc(sizeof(No));
    new->number = number_info();
    new->next = NULL;
    new->previus = NULL;
    if (list->begin == NULL) {
        list->begin = new;
        list->end = new;
        return;
    }
    new->next = list->begin;
    list->begin->previus = new;
    list->begin = new;
}

void add_elements_meio(List *list, int n) {

    No *aux, *new = malloc(sizeof(No));
    new->number = number_info();
    if (list->begin == NULL) {
        new->next = NULL;
        new->previus = NULL;
        list->begin = new;
        list->end = new;
        return;
    } 
    aux = list->begin;
    while (aux->next != NULL && aux->number != n) {
        aux = aux->next;
    }

    if (aux->number == n) {
        new->next = aux->next;
        new->previus = aux->previus;
        if (aux->next != NULL) {
            aux->next->previus = new;
        }
        aux->next = new;
    } else {
        new->previus = list->end;
        new->next = NULL;
        list->end->next = new;
        list->end = new;
    }
 
}

No *remove_element(List *list) {
    No *remove = NULL;
    if (list->begin != NULL) {
        remove = list->begin;
        list->begin = remove->next;
    }
    return remove;
}

void print_list(List *list) {
    if (list->begin == NULL) {
        printf("A lista esta vazia..\n");
        return;
    }
    No *aux = list->begin;
    while (aux != NULL) {
        printf("[%d] ", aux->number);
        aux = aux->next;
    }

    printf("\n");
    printf("O primeiro number e [%d]\nO ultimo number [%d]\n", list->begin->number, list->end->number);
}

int main() {
    List list;
    start_list(&list);

    No *remove = NULL;
    int n, _continue = 0;

    do {
        printf("---Menu---\n");
        printf("[1] Adicionar\n[2] Remover\n[3] Imprimir\n[4] Add_meio\n[0] Finalizar..: ");
        scanf("%d", &_continue);
        buffer();

        if (_continue < 0 || _continue > 4) {
            printf("Parametro nao encontrado! \n");
            _continue = 0;
        }
        system("cls");

        switch (_continue)
        {
        case 1:
            add_number_begin(&list);
            break;
        case 2:
            remove = remove_element(&list);
            if (remove != NULL) {
                printf("O numero [%d] foi removido..\n", remove->number);
            } else {
                printf("Nao a elementos para serem removidos..\n");
            }
            free(remove);
            break;
        case 3:
            print_list(&list);
            break;
        case 4:
            printf("Onde? ");
            scanf("%d", &n);
            buffer();
            add_elements_meio(&list, n);
            break;
        }
    } while (_continue != 0);

    return 0;
}