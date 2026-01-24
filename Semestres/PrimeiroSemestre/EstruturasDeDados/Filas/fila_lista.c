#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buffer() {
    int c;
    while ((c= getchar()) != '\n' && c != EOF);
 }

typedef struct no {
    int number;
    struct no *next;
}No;

typedef struct {
    No *begin;
}List;

void start_list(List *list) {
    list->begin = NULL;
}

int report_elemnt() {
    int number;
    printf("Report one number: ");
    scanf("%d", &number);
    buffer();

    return number;
}
  
void add_element(List *list) {
    No *aux, *new = malloc(sizeof(No));
    new->number = report_elemnt();
    new->next = NULL;
    if (list->begin == NULL) {
        list->begin = new;
        return;
    } else if (new->number > 60) {
        printf("Idade preferencial identificada..\n");
        new->next = list->begin;
        list->begin = new;
        return;
    }
    aux = list->begin;
    while (aux->next != NULL) {
        aux = aux->next;
    } 
    aux->next = new;
}

No *remove_elemente(List *list) {
    No *remover = NULL;
    if (list->begin != NULL) {
        remover = list->begin;
        list->begin = remover->next;

        return remover;
    }
    return remover;
}

void printList(List *list) {
    No *aux = list->begin;
    while (aux != NULL) {
        printf("[%d] ", aux->number);
        aux = aux->next;
    }
    printf("\n");
}

int main() {
    system("cls");
    List list;
    start_list(&list);

    No *remover;

    int proceed = 0;
    do {
        printf("---Menu---\n[1] Adicione\n[2] remover\n[3] Mostre Lista\n[0] Finalizar..: ");
        scanf("%d", &proceed);
        system("cls");

        switch (proceed)
        {
        case 1:
            add_element(&list);
            break;
        
        case 2:
            remover = remove_elemente(&list);
            if (remover != NULL) {
                printf("O valor [%d] foi removido..\n", remover->number);
            } else {
                printf("Nao a mais elementos para serem removidos.\n");
            }
            break;

        case 3:
            printList(&list);
            break;

        default:
            printf("\tOpcao nao encontrada.\n");
            break;
        }

        if (proceed > 3 || proceed < 0) {
            printf("Parametro nao encontrado..\n");
            printf("Sera considerado [0].\n");
            proceed = 0;
        }
    } while (proceed != 0);

    return 0;
}
