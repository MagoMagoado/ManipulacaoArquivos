#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){

    char titulo[30], nome_arquivo[34];

    printf("Escolha título arquivo: ");
    fgets(titulo, 30, stdin);
    //retira quebra de linha do final do código
    titulo[strlen(titulo)-1] = '\0';

    //concatena o titulo com ".txt"
    strcat(strcpy(nome_arquivo, titulo), ".txt");
    printf("%s\n", nome_arquivo);

    FILE *arquivo;
    //Como o arquivo está no mesmo diretório, não é preciso indicar caminho
    arquivo = fopen(nome_arquivo, "w");
    //Se o ponteiro não apontar para nenhum arquivo
    if (arquivo==NULL){
        printf ("Erro na abertura do arquivo.");
        return 0;
    }
    else{
        char conteudo_arquivo[100];
        /*//limpar buffer
        getchar();*/
        printf("Escreva o conteudo do arquivo:\n");
        fgets(conteudo_arquivo, 100, stdin);
        conteudo_arquivo[strlen(conteudo_arquivo)-1] = '\0';

        fprintf(arquivo, "%s",conteudo_arquivo);
    }
    fclose(arquivo);
    return 0;
}