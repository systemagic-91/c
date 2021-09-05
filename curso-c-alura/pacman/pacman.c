#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pacman.h"
#include "mapa.h"
#include "ui.h"

MAPA map;
POSICAO pacman;
int temPilula=0;

int main(){

    lerMapa(&map);
    encontraPacman(&map, &pacman, PACMAN);

    do {        
        
        imprimeMapa(&map);
        
        char comando;
        scanf(" %c", &comando);
        
        if (validaDirecao(comando))
            move(comando);

        if (comando == BOMBA)
            explode(pacman.x, pacman.y, AREA_EXPLOSAO);

        fantasmas();

    } while (!acabou());    

    desalocarMapa(&map);
}

void explode(){

    if(!temPilula) return;

    explode2(pacman.x, pacman.y, 0, 1, AREA_EXPLOSAO);
    explode2(pacman.x, pacman.y, 0, -1, AREA_EXPLOSAO);
    explode2(pacman.x, pacman.y, 1, 0, AREA_EXPLOSAO);
    explode2(pacman.x, pacman.y, -1, 0, AREA_EXPLOSAO);

    temPilula = 0;
}

void explode2(int x, int y, int somaX, int somaY, int qnt){

    if (qnt == 0) return;

    int novoX = x + somaX;
    int novoY = y + somaY;

    if(!validaMovimento(&map, novoX, novoY)) return;
    if(ehParede(&map, novoX, novoY)) return;

    map.matriz[novoX][novoY] = VAZIO;   
    explode2(novoX, novoY, somaX, somaY, qnt-1);
}


int destinoFantasma(int xAtual, int yAtual, int * xDestino, int * yDestinho){

    int opcoes[4][2] = {
        {xAtual, yAtual+1},
        {xAtual+1, yAtual},
        {xAtual, yAtual-1},
        {xAtual-1, yAtual}
    };

    srand(time(0));

    for (int i = 0 ; i < 10 ; i++) {

        int posicao = rand() % 4;

        if(podeAndar(&map, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){

               *xDestino = opcoes[posicao][0];
               *yDestinho = opcoes[posicao][1];

               return 1;
        }
    }

    return 0;
}


void fantasmas(){

    MAPA copia;

    copiarMapa(&copia, &map);
    
    for(int i = 0 ; i < copia.linhas ; i++){

        for(int j = 0 ; j < copia.linhas ; j++){

            if(copia.matriz[i][j] == FANTASMA){

                int xDestino, yDestino;
                int encontrou = destinoFantasma(i,j, &xDestino, &yDestino);

                if(encontrou){
                    andarNoMapa(&map, i, j, xDestino, yDestino);
                }
            }
        }
    }

    desalocarMapa(&copia);
}


void move(char direcao){    

    if(!validaDirecao(direcao))
        return;

    int proximoX = pacman.x;
    int proximoY = pacman.y;

    switch (direcao){

    case ESQUERDA:
        proximoY--;
        break;

    case CIMA:
        proximoX--;
        break;
    
    case BAIXO:
        proximoX++;
        break;

    case DIREITA:
        proximoY++;
        break;        
    } 

    if(!podeAndar(&map, PACMAN, proximoX, proximoY))
        return;   

    if (ehPersonagem(&map, PILULA, proximoX, proximoY)){
        temPilula = 1;
    }

    andarNoMapa(&map, pacman.x, pacman.y, proximoX, proximoY);

    pacman.x = proximoX;
    pacman.y = proximoY;
}


int validaDirecao(char direcao){
    return (direcao == ESQUERDA || direcao == CIMA || direcao == BAIXO || direcao == DIREITA);        
}


int acabou(){
     
    POSICAO pos;

    int ganhou = !encontraPacman(&map, &pos, FANTASMA);
    int perdeu = !encontraPacman(&map, &pos, PACMAN);

    return ganhou || perdeu;
}