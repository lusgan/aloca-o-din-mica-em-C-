#include <stdio.h>
#include <stdlib.h>

int *uniao( int *v1, int n1, int *v2, int n2, int *p3 );
void mostra(int v[],int n);
int existeNoVetor(int n,int v[], int tam);

int main(){

    int n1,*v1,n2,*v2,*p3;
    int tamanhoU = 0;
    p3 = &tamanhoU;
    printf("Quantos elementos o primeiro vetor possui? ");
    scanf("%d",&n1);

    v1 = malloc(sizeof(int)*n1);

    printf("\n Insira esses elementos: ");
    for(int i = 0; i<n1;i++){
        scanf("%d",v1+i);
    }

    printf("Quantos elementos o SEGUNDO vetor possui? ");
    scanf("%d",&n2);

    v2 = malloc(sizeof(int)*n2);

    printf("\n Insira esses elementos: ");
    for(int i = 0; i<n2;i++){
        scanf("%d",v2+i);
    }

    int *Vuniao = uniao(v1,n1,v2,n2,p3);

    mostra(Vuniao,*p3);

    printf("Vuniao tem tamanho : %d",*p3);

    free(v1);
    free(v2);


    return 0;
}

int *uniao( int *v1, int n1, int *v2, int n2, int *p3 ){

    int *Vuniao;
    Vuniao = malloc(sizeof(int)*n1);

    for(int k = 0; k<n1;k++){
        Vuniao[k] = v1[k];
    }

    int aux = 0;

    for(int i = 0; i<n2;i++){
        if(existeNoVetor(v2[i],Vuniao,n1)==0){
            Vuniao = realloc(Vuniao,sizeof(int)*n1+aux);
            Vuniao[n1+aux] = v2[i];
            aux++;
        }
    }


    *p3 = n1+aux;
    return Vuniao;

}

void mostra(int v[],int n){

    for(int i = 0; i<n;i++){
        printf("%d ",v[i]);
    }
    printf("\n");

}

int existeNoVetor(int n,int v[],int tam){

    for(int i = 0; i<tam;i++){
        if(n==v[i]){
            return 1;
        }
    }

    return 0;

}
