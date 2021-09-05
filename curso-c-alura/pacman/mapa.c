#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void lerMapa(MAPA * map){

    FILE * arquivo = fopen("mapa.txt", "r");

    if(arquivo == 0){
        printf("Erro na leitura do mapa!\n");
        exit(1);
    }

    fscanf(arquivo, "%d %d", &(map->linhas), &(map->colunas));

    alocarMapa(map);

    for (int i = 0; i < (*map).linhas ; i++) {
        fscanf(arquivo, "%s", map->matriz[i]);
    }

    fclose(arquivo);    
}

void alocarMapa(MAPA * map){

    // alocando espaço pra X endereços (linhas)
    (*map).matriz = malloc(sizeof(char*) * (*map).linhas); 

    // alocando espaço pra X colunas em cada linha.
    for (int i = 0; i < (*map).linhas ; i++) {
        (*map).matriz[i] = malloc(sizeof(char) * (*map).colunas+1); // colunas+1 -> \0
    }
}

void desalocarMapa(MAPA * map){

    // liberando memoria das colunas.
    for (int i = 0; i < (*map).linhas ; i++) {
        free((*map).matriz[i]);
    }    

    // liberando memoria das linhas. (vetor de endereços).
    free((*map).matriz);
}


int encontraPacman(MAPA * map, POSICAO * pos, char c){

    for (int i = 0 ; i < (*map).linhas ; i++) {
        for (int j = 0 ; j < (*map).colunas ; j++) {
            if((*map).matriz[i][j] == c){
                (*pos).x = i;
                (*pos).y= j;
                return 1;
            }
        }
    }

    return 0;
}


int validaMovimento(MAPA * map, int x, int y){

    if(x >= (*map).linhas)
        return 0;   

    if(y >= map->colunas)
        return 0;   
    
    return 1;
}


int posicaoVazia(MAPA * map, int x, int y){
    return (*map).matriz[x][y] == VAZIO;
}


void andarNoMapa(MAPA * map, int xOrigem, int yOrigem, int xDestinho, int yDestino){

    char personagem = map->matriz[xOrigem][yOrigem];
    map->matriz[xDestinho][yDestino] = personagem;
    map->matriz[xOrigem][yOrigem] = VAZIO;
}

void copiarMapa(MAPA * mapDestino, MAPA * mapOrigem){
    
    mapDestino->linhas = mapOrigem->linhas;
    mapDestino->colunas = mapOrigem->colunas;
    
    alocarMapa(mapDestino);

    for (int i = 0; i < mapOrigem->linhas; i++){
        strcpy(mapDestino->matriz[i], mapOrigem->matriz[i]);
    }
    
}


int podeAndar(MAPA * map, char personagem, int x, int y){
    return validaMovimento(map, x, y) && !ehParede(map, x, y) && !ehPersonagem(map, personagem, x, y);
}


int ehParede(MAPA * map, int x, int y){
    return map->matriz[x][y]== PAREDE_VERTICAL || map->matriz[x][y]== PAREDE_HORIZONTAL; 
}

int ehPersonagem(MAPA * map, char personagem, int x, int y){
    return map->matriz[x][y] == personagem;
}