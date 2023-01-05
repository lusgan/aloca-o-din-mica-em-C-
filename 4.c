#include <stdio.h>
#include <stdlib.h>

void mostra(int v[], int n);
int main(){

    int *v,n;
    printf("Insira a quantidade de elementos do vetor: ");
    scanf("%i",&n);

    v=malloc(sizeof(int)*n);
    printf("\n Insira os elementos do vetor:\n");

    for(int i = 0; i<n;i++){
        scanf("%i",v+i);
    }

    int *Vp,*Vn,aux = 0;
    int auxn = 0;
    Vp = malloc(0);
    Vn = malloc(0);

    for(int i = 0; i<n; i++){
        if(*(v+i)>0){
            Vp = realloc(Vp,sizeof(Vp)+4);
            *(Vp+ aux) = v[i];
            aux++;
        }
        else{
            Vn = realloc(Vn,sizeof(Vn)+4);
            *(Vn+ auxn) = v[i];
            auxn++;
        }
    }

    printf("Vetor digitado: ");
    mostra(v,n);
    printf("\nVetor dos positivos: ");
    mostra(Vp,aux);
    printf("Vetor dos negativos: ");
    mostra(Vn,auxn);

    free(Vp);
    free(Vn);
    free(v);

    return 0;
}

void mostra(int v[],int n){

    for(int i = 0; i<n;i++){
        printf("%d ",v[i]);
    }
    printf("\n");

}
