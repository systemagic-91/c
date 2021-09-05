#ifndef _MAPA_H_
#define _MAPA_H_

#define PACMAN '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'
#define AREA_EXPLOSAO 3

struct st_mapa {

    char **matriz;
    int linhas; 
    int colunas;
};

typedef struct st_mapa MAPA;

struct st_posicao{

    int x;
    int y;
};

typedef struct st_posicao POSICAO;

void lerMapa(MAPA * map);
void alocarMapa(MAPA * map);
void desalocarMapa(MAPA * map);
void andarNoMapa(MAPA * map, int, int, int, int);
void copiarMapa(MAPA * mapDestino, MAPA * mapOrigem);

int encontraPacman(MAPA * map, POSICAO * pos, char);
int validaMovimento(MAPA * map, int, int);
int posicaoVazia(MAPA * map, int, int);
int podeAndar(MAPA * map, char, int, int);
int ehParede(MAPA * map, int, int);
int ehPersonagem(MAPA * map, char, int, int);


#endif