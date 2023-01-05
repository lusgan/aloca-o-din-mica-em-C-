
#include <stdio.h>
#include <stdlib.h>

float *clone(float *v, int n);
int main()
{
    int n;
    printf("Diga o tamanho do vetor: ");
    scanf("%d",&n);
    float v[n];

    printf("Insira os elementos do vetor:\n");
    for (int i =0; i<n;i++){
        scanf("%f",&v[i]);
    }

    float *clo;
    clo = clone(v,n);

    printf("O clone esta abaixo:\n");
    for(int i = 0; i<n;i++){
        printf("%.2f\n",*(clo+i));
    }

    return 0;

}

float *clone(float *v, int n){

    float *p;
    p = malloc(sizeof(float)*n);

    for(int i = 0; i<n; i++){
        *(p+i) = *(v + i);
    }

    return p;

}
