#include <stdio.h>
# include <stdlib.h>
#include <string.h>

int main(){

    char titulo[30], nome_arquivo[34];

    printf("Escolha título arquivo: ");
    fgets(titulo, 30, stdin);
    //retira quebra de linha do final do código
    titulo[strlen(titulo)-1] = '\0';

    //concatena o titulo com ".txt"
    strcat(strcpy(nome_arquivo, titulo), ".txt");

    //renomeia o arquivo com o nome do titulo
    rename("arquivo_base.txt", nome_arquivo);
    printf("o titulo arquivo_base.txt mudou para %s\n\n", nome_arquivo);

    FILE *arquivo;
    //Como o arquivo está no mesmo diretório, não é preciso indicar caminho
    //a+ é leitura e inserir coisas no arquivo
    arquivo = fopen(nome_arquivo, "r");
    //Se o ponteiro não apontar para nenhum arquivo
    if (arquivo==NULL){
        printf ("Erro na abertura do arquivo.");
        return 0;
    }
    else{
        char conteudo_arquivo[2000];

        //faz a captura do conteúdo. [^\n] conta os espaços em branco
        fscanf(arquivo, "%[^\n]", conteudo_arquivo);
        printf("%s\n", conteudo_arquivo);
    }
    fclose(arquivo);
    return 0;
}