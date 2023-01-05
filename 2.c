#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *repetidor( char *palavra, int n);

int main(){

    int n;
    char palavra[100];
    printf("Insira uma palavra: ");
    scanf("%s",palavra);

    printf("Quantas vezes quer q repita? ");
    scanf("%d",&n);

    char *newWord;
    newWord = repetidor(palavra,n);

    printf("%s",newWord);

    return 0;
}

char *repetidor( char *palavra, int n){

    char *nova_string;
    nova_string = malloc(strlen(palavra)*n +1);

    for(int i = 0; i<n;i++){
        strcpy(nova_string+i*strlen(palavra),palavra);
    }

    return nova_string;

}
