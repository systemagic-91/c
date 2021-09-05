#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "mapa.h"

char desenhoFantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoParede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoPacman[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhoPilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhoVazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void imprimeMapa(MAPA * map){

    for (int i = 0; i < map->linhas ; i++) {

        for(int parte = 0 ; parte < 4 ; parte++){

            for (int j = 0; j < map->colunas ; j++) {

                switch (map->matriz[i][j]) {

                case FANTASMA:

                    imprimeParte(desenhoFantasma, parte);
                    break;

                case PACMAN:

                    imprimeParte(desenhoPacman, parte);
                    break;

                case PILULA:

                    imprimeParte(desenhoPilula, parte);
                    break;                    
                
                case PAREDE_VERTICAL:
                case PAREDE_HORIZONTAL:

                    imprimeParte(desenhoParede, parte);
                    break;  

                case VAZIO:

                    imprimeParte(desenhoVazio, parte);
                    break;

                }
            }

            printf("\n");
        }        
    }
}

void imprimeParte(char desenho[][7], int parte){
    printf("%s", desenho[parte]);
}