#include <stdio.h>
#include <string.h>


char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void abertura();
void escolhePalavra();
void desenhaForca();
void chuta();

int jachutou(int);

int main() {

	int acertou = 0;
	int enforcou = 0;


    escolhePalavra();
	abertura();

	do {
		
		printf("\nVocê já deu %d chutes\n", tentativas);
		
        desenhaForca();

		chuta();


	} while (!acertou && !enforcou);
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

	chutes[tentativas] = chute;
	tentativas++;
}

int jaChutou(char letra){
    
    int achou = 0;

    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaForca(){

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
    sprintf(palavrasecreta, "MELANCIA");
}

