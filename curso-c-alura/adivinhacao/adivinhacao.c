#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("\n");
    printf("************************************\n");
    printf("* BEM VINDO AO JOGO DE ADIVINHAÇÃO *\n");
    printf("************************************\n");

    // define uma "semente" diferente a cada execução do programa
    srand(time(0));

    // time(0) -> devolve o número de segs desde EPOCH até a data atual.
    int numeroSecreto = rand() % 100; // de 0 a 99    

    double pontuacao = 1000.0;    

    int tentativas = 0;
    int palpite = 0;
    int acertou;
    int maior;
    int nivel;
    int i;

    printf("\nEscolha o nível de dificuldade?");
    printf("\n(1) - Fácil");
    printf("\n(2) - Médio");
    printf("\n(3) - Difícil\n");
    scanf("%d", &nivel); 

    switch (nivel) {
    case 1:
        tentativas = 15;
        break;
    case 2:
        tentativas = 10;
        break;
    case 3:
        tentativas = 5;
        break;
    
    default:
        printf("\nOpção inválida.\n");
        printf("Inicando jogo no nível fácil.\n");
        tentativas = 15;
        break;
    }
   
    for (i = 1 ; i <= tentativas ; i++ ) {        

        printf("\nTentativa %d de %d\n", i, tentativas);
        printf("Seu palpite: ");
        scanf("%d", &palpite);

        if(palpite < 0){

            printf("\nNumeros negativos não são válidos!\n");            

            // vai direto para a proxima iteração do loop (i++)
            // sem executar o codigo abaixo desse bloco
            continue; 
        }        

        acertou = (palpite == numeroSecreto); // 0 -> falso | != 0 -> verdadeiro
        maior = (palpite > numeroSecreto);        

        if (acertou){
            
            break;
        } else if (maior) {
            printf("\nSeu palpite foi maior que o número secreto!\n");
        } else {
            printf("\nSeu palpite foi menor que o número secreto!\n");
        }        

        // abs() -> valor absoluto (stdlib.h)
        pontuacao -= abs(palpite - numeroSecreto) / 2.0;
    }
    
    if (acertou){
        printf("Parabéns\n");
        printf("Acertou na tentativa: %d\n", i);
        printf("\nTotal de Pontos: %.1f!\n", pontuacao);
    } else{        
        printf("\nVoce Perdeu! Tente novamente!\n");
    }
}