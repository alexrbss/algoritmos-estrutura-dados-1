#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main(void){
    
    char * nome = (char*) malloc(50* sizeof(char));
    
    if(nome == NULL){
        exit(1);
    }
    
    printf("Digite seu nome: \n");
    scanf(" %[^\n]s", nome); 

    printf("Seu Nome e: %s", nome);
    
    free(nome);
    
    return 0;
}