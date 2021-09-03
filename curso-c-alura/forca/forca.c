#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"


char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;

int main() {	

	abertura();
    escolhePalavra();

	do {		
				
        desenhaForca();
		chuta();
        chutesDados++;

	} while (!acertou() && !enforcou());


    if(acertou()){
        printf("\nParabéns voce acertou a palavra!\n");
    } else {
        printf("\nVoce foi enforcado!\n");
    }

    adicionaPalavra();
}

void abertura(){

    printf("*********************************\n");
    printf("********* JOGO DE FORCA *********\n");
    printf("*********************************\n\n");
}

void chuta() {
	char chute;
	printf("\nQual letra? ");
	scanf(" %c", &chute);

	chutes[chutesDados] = chute;	
}

int jaChutou(char letra){
    
    int achou = 0;

    for(int j = 0; j < chutesDados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaForca(){

    int erros = chutesErrados();
    printf("\n---------------------------------");
    printf("\nVocê já deu %d chutes\n", chutesDados);

    printf("  _______       \n");
    printf(" |/      |      \n");
    
    printf(" |      %c%c%c  \n",  (erros >= 1 ? '(':' '),
                                  (erros >= 1 ? '_':' '),
                                  (erros >= 1 ? ')':' '));

    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\':' '),
                                 (erros >= 2 ? '|':' '),
                                 (erros >= 3 ? '/':' '));

    printf(" |       %c     \n", (erros >= 4 ? '|':' '));

    printf(" |      %c %c   \n", (erros >= 4 ? '/':' '), 
                                 (erros >= 4 ? '\\':' '));

    printf(" |              \n");
    printf("_|___           \n");
    
    printf("\n\n");

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jaChutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    
    printf("\n");
}

void escolhePalavra(){
    
    FILE * arquivo = fopen("dados.txt", "r");

    if(arquivo == 0){
        printf("\nERRO: Falha no arquivo de dados\n");
        exit(1);
    }

    int quantPalavras;
    fscanf(arquivo, "%d", &quantPalavras);

    srand(time(0));
    int randomico = rand() % quantPalavras;

    for (int i = 0; i <= quantPalavras; i++) {
        fscanf(arquivo, "%s", palavrasecreta);
    }    

    fclose(arquivo);
}

int enforcou (){
    return chutesErrados() >= 5;
}

int acertou () {

    for (int i = 0 ; i < strlen(palavrasecreta) ; i++) {
        if(!jaChutou(palavrasecreta[i])){
            return 0;
        }
    }

    return 1;    
}

void adicionaPalavra(){

    char opcao;
    char novaPalavra[TAMANHO_PALAVRA];
    printf("\nDeseja adicionar uma palava (S/N)? ");
    scanf(" %c", &opcao);

    switch (opcao){

    case 'S':        

        printf("\nNova palavra: ");
        scanf("%s", novaPalavra);

        atualizaArquivo(novaPalavra);

        break;

    case 'N':
        
        break;    

    default:
        break;
    }

}

void atualizaArquivo(char novaPalavra[]){

    FILE * arquivo = fopen("dados.txt", "r+");

    if(arquivo == 0){
        printf("\nERRO: Falha no arquivo de dados\n");
        exit(1);
    }

    int quantidade;
    fscanf(arquivo, "%d", &quantidade);
    fseek(arquivo, 0, SEEK_SET);

    quantidade++;

    fprintf(arquivo, "%d\n", quantidade);

    fseek(arquivo, 0, SEEK_END);        
    fprintf(arquivo, "\n%s", novaPalavra);

    fclose(arquivo);
}


int chutesErrados(){

    int erros = 0;

    for (int i = 0 ; i < chutesDados ; i++) {
        
        int existe = 0;

        for (int j = 0 ; j < strlen(palavrasecreta) ; j++) {
            
            if(chutes[i] == palavrasecreta[j]){
                existe = 1;
                break;
            }
        }

        if (!existe) erros++;
    }

    return erros;
}