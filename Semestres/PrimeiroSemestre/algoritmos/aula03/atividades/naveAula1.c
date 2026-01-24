#include <stdio.h>
#include <stdlib.h>

#define tanqueCheio 5000
int main()
{

    //Checar o nivel do combustivel..
    float combustivel = 0.0;
    printf("Qual e seu combustivel atual? ");
    scanf("%f", &combustivel);

    double porcentagem = (combustivel / tanqueCheio) * 100;
    if(porcentagem < 20) {
        printf("O tanque esta com %.1lf porcento de sua capacidade maxima. \nFavor reabasteça... \n", porcentagem);
    } else if (porcentagem < 50) {
        printf("O tanque esta com %.1lf porcento de sua capacidade maxima. \nFavor prestar atencao... \n", porcentagem);
    } else {
        printf("O tanque esta com %.1lf porcento de sua capacidade maxima. \nBoa viagem...\n", porcentagem);
    }

    return 0;
}
