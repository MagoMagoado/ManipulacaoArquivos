#include <stdio.h>
# include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo;
    //Como o arquivo está no mesmo diretório, não é preciso indicar caminho
    arquivo = fopen("arquivo_base.txt", "r");
    //Se o ponteiro não apontar para nenhum arquivo
    if (arquivo==NULL){
        printf ("Erro na abertura do arquivo.");
        return 0;
    }
    else{
        char conteudo_arquivo[2000], c;
        int tamanho, new_tamanho, test = 0, conta_vogais = 0;

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
            if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                    conta_vogais++;
            }
        }
        printf("Quantidade de vogais: %d\n", conta_vogais);
    }
    fclose(arquivo);
    return 0;
}