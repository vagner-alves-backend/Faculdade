#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cadastre, confirme = 'N';
    int turma = 0;
    printf("----------------------------------------------------------\n");
    printf("Cadastre Alunos...\n");
    printf("A quantos alunos na sua turma? ");
    scanf("%d", &turma);
    printf("..........................................................\n");
    while (turma == 0) {
        printf("Sua turma nao pode ter 0 alunos..\nCaso nao tenha alunos para passar pode encerrar o progama!\nDeseja encerrar o progama?\n[S/N]: ");
        scanf(" %c", &confirme);
        printf("..........................................................\n");
        if (confirme == 's' || confirme == 'S') {
            printf("Progama encerrado..! \n");
            break;
        } else {
            printf("Informe alunos: ");
            scanf("%d", &turma);
        }
    }
    
//cadastro Aluno...
    
    if (turma > 0) {
        int atual = 0;
        int check = 0;
        int reprovados = 0;
        int aprovados = 0;
        float nota[turma];
        do {
            char nome[turma][50];
            printf("--------------------------Aluno---------------------------\n");
            printf("Nome: ");
            scanf("%s", nome[atual]);
            getchar();


            printf("Nota: ");
            scanf("%f", &nota[atual]);

            if (nota[atual] < 0) {
                printf("..........................................................\n");
                printf("Nota invalida...\nFavor tente novamente!\n");
                nota[atual] = 0;
                break;
            }

            if (nota[atual] < 6) {
                printf("Aluno %s abaixo da media...\n", nome[atual]);
                reprovados++;
            }else {
                printf("Aluno %s acima da media...\n", nome[atual]);
                aprovados++;
            }

            if (check == turma) {
                printf("Todos os alunos foram cadastrados....\n");
                break;
            }
            check++;
            atual++;

            printf("..........................................................\n");
            printf("Deseja cadastrar outro aluno? [S/N]: ");
            scanf(" %c", &cadastre);
            if (cadastre == 'S' || cadastre == 's' || cadastre == 'n' || cadastre == 'N') {
                cadastre = cadastre;
            } else {
                printf("Parametro nao encontrado...\nSera considerado [N].\n");
                cadastre = 'N';
            }
        } while(cadastre == 's' || cadastre == 'S');

        printf("--------------------------Media---------------------------\n");

        float maior = nota[0];
        float menor = nota[0];
        for (int index = 0; index < check; index++) {
            if (nota[index] < menor) {
                menor = nota[index];
            }
            if (nota[index] > maior) {
                maior = nota[index];
            }
        }
        printf("Maior: %.2f \nMenor: %.2f\n", maior, menor);

        float total, media = 0.0;
        for (int at = 0; at < check; at++) {
            total = nota[at] + total;
        }
        media = total/2;
        printf("Total: %.2f \nMedia: %.2f \n", total, media);
        printf("----------------------------------------------------------\n");
        printf("Foram Aprovados: %d \nForam Reprovados: %d \n", aprovados, reprovados);
        printf("..........................................................\n");
        printf("==========================================================\n");
    }

    return 0;
}