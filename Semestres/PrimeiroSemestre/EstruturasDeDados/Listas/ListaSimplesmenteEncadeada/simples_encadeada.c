#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_buffer() {
    int buffer = 0;
    while ((buffer = getchar()) != '\n' && buffer != EOF);
}

typedef struct {
    int identifier;
    char task[100];
}list_tasks;

typedef struct no {
    list_tasks task;
    struct no *next;
}No;

typedef struct {
    No *begin;
    int size_list;
}List;

void start_list(List *list) {
    list->begin = NULL;
    list->size_list = 0;
}

list_tasks create_task(No *identifier) {
    list_tasks add;
    No *temp_list = NULL;
    int valid = 0;
    int iden = 0;

    printf("---Crie uma tarefa---\n");
    printf("Tarefa: ");
    fgets(add.task, 100, stdin);
    add.task[strcspn(add.task, "\n")] = '\0';

    do {
        temp_list = identifier;
        printf("Informe o identificador da tarefa..: ");
        scanf("%d", &iden);
        clear_buffer();

        while (temp_list != NULL && temp_list->task.identifier != iden) {
            temp_list = temp_list->next;
        }
        if (temp_list != NULL) {
            printf("Identificador ja existente..\n");
            valid = 1;
        } else {
            valid = 0;
        }
    } while (valid != 0);

    add.identifier = iden;
    return add;
}

void add_tasks_list(List *list) {
    No *valid = list->begin;
    No *newTask = malloc(sizeof(No));
    newTask->task = create_task(valid);
    newTask->next = NULL;
    
    if (list->begin == NULL) {
        list->begin = newTask;
        list->size_list++;
        return;
    }

    newTask->next = list->begin;
    list->begin = newTask;
    list->size_list++;
}

void print_list(List *list) {
    No *list_temp = list->begin;
    while (list_temp != NULL) {
        printf("\t[%d] %s \n", list_temp->task.identifier, list_temp->task.task);
        list_temp = list_temp->next;
    }
    printf("...........................\n");
}

No *remove_task(List *list, int task) {
    No *remove = NULL;
    if (list->begin != NULL) {
        if (list->begin->task.identifier == task) {
            remove = list->begin;
            list->begin = remove->next;
            list->size_list--;
        } else {
            No *list_temp = list->begin;
            while (list_temp->next != NULL && list_temp->next->task.identifier != task) {
                list_temp = list_temp->next;
            }
            if (list_temp != NULL) {
                remove =list_temp->next;
                list_temp->next = remove->next;
                list->size_list--;
            }
        }
    }
    return remove;
}
 
int main() {
    system("cls");
    List list;
    start_list(&list);
    No *remove = NULL;

    int option = 0;
    int iden;
    do {
        printf("-=-=-Menu-=-=-\n");
        printf("[1] Adicione\n[2] Remova\n[3] Tarefas\n[0] Finalize..: ");
        scanf("%d", &option);
        clear_buffer();
        system("cls");

        if (option == 1) {
            add_tasks_list(&list);
        } else if (option == 2) {
            printf("Identificador da tarefa que vc deseja remover..: ");
            scanf("%d", &iden);
            clear_buffer();

            remove = remove_task(&list, iden);
            if (remove != NULL) {
                printf("A tarefa..: [%d] %s.. Foi removida.\n", remove->task.identifier, remove->task.task);
            } else {
                printf("Tarefa nao encontrada..\n");
            }
            free(remove);

        } else if (option == 3) {
            printf("-=-=-Suas tarefas sao-=-=-\n");
            print_list(&list);
        } else if (option != 0) {
            printf("Parametro nao encontrado, sera consideerado 0..\n");
            option = 0;
        }

        if (list.size_list > 0) {
            printf("----------------------------------------\n");
            printf("Foram adicionado [%d] na sua lista..\n", list.size_list);
            printf("----------------------------------------\n");
        }
    } while (option != 0);

    return 0;
}