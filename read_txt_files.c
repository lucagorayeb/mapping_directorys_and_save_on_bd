#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *ponteiro_arquivo;
    char texto_str[20];
    ponteiro_arquivo = fopen("teste.txt", "r");
    
    while(fgets(texto_str, 20, ponteiro_arquivo) != NULL){
        printf("%s", texto_str);
    }

    fclose(ponteiro_arquivo);
    printf("Arquivo lido com sucesso!\n");
    return 0;
}

int read_directorys_text_files(){

}

int read_text_files(){

}