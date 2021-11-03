#include <stdio.h>
# include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo;
    //Como o arquivo está no mesmo diretório, não é preciso indicar caminho
    //a+ é leitura e inserir coisas no arquivo
    arquivo = fopen("arquivo_base.txt", "a+");
    //Se o ponteiro não apontar para nenhum arquivo
    if (arquivo==NULL){
        printf ("Erro na abertura do arquivo.");
        return 0;
    }
    else{
        char conteudo_arquivo[2000], c;
        int tamanho, new_tamanho, test = 0, conta_linhas = 0;

        //lê o arquivo inteiro e mostra quantidade de letras
        while(fgets(conteudo_arquivo,2000,arquivo)!=NULL){
            //printf("%s\n", conteudo_arquivo);
            tamanho = strlen(conteudo_arquivo);
            printf("\nTotal de letras do arquivo (com espaços em branco): %d\n",tamanho);
        }
        //reposicionar ponteiro de leitura para inicio do arquivo
        rewind(arquivo);
        //contar quantos caracteres vazios ou quebra de linhas há no arquivo
        while(!feof(arquivo)){
            c = getc(arquivo);
            if ( c == ' ' || c == '\n' ){
                if (test == 0){
                    conta_linhas++;
                    test = 1;
                }
            }
            else{
                if ( test == 1 )
                    test = 0;
            }
        }
        printf("Quantidade de vazios: %d\n", conta_linhas);
        new_tamanho = tamanho-conta_linhas;
        printf("\nTotal de letras do arquivo (sem espaços em branco): %d\n",new_tamanho);

        //adicionando no final do arquivo a quantidade de caracteres
        fprintf(arquivo,"\n%d",new_tamanho);

    }
    fclose(arquivo);
    return 0;
}