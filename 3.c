#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    float *valores;

    printf("Insira a quantidade de elementos do vetor: ");
    scanf("%d",&n);
    valores = malloc(sizeof(float)*n);

    printf("\nDigite os elementos do vetor:\n");

    float soma = 0;
    for(int i = 0; i<n; i++){
        scanf("%f",valores + i);
        soma += *(valores+i);
    }

    float media = soma/n;

    float *maiores_que_media;
    maiores_que_media = malloc(sizeof(valores));
    int k = 1;
    int aux = 0;

    for(int i = 0; i<n;i++){
        if(*(valores+i)>media){
            maiores_que_media = realloc(maiores_que_media,sizeof(float)*k);
            k++;
            *(maiores_que_media+aux) = *(valores+i);
            aux++;
        }
    }

    printf("Os valores maiores que a media sao:\n");
    for(int i = 0; i<sizeof(maiores_que_media)/sizeof(maiores_que_media[0]);i++){
        printf("%.2f ",*(maiores_que_media+i));
    }

    free(maiores_que_media);
    free(valores);


    return 0;
}
