#include <stdio.h>
# include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo;
    //Como o arquivo está no mesmo diretório, não é preciso indicar caminho
    //a+ é leitura e inserir coisas no arquivo
    arquivo = fopen("arquivo_linhas.txt", "r");
    //Se o ponteiro não apontar para nenhum arquivo
    if (arquivo==NULL){
        printf ("Erro na abertura do arquivo.");
        return 0;
    }
    else{
        char c;
        int conta_linhas = 0;

        //contar quantos caracteres vazios ou quebra de linhas há no arquivo
        while(!feof(arquivo)){
            c = getc(arquivo);
            if ( c == '\n' ){
                    conta_linhas++;
                }
        }
        //como não há quebra na última linha, não contabiliza, por isso "conta_linhas+1"
        printf("Quantidade de linhas: %d\n", conta_linhas+1);
    }
    fclose(arquivo);
    return 0;
}