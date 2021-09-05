#ifndef _PACMAN_H_
#define _PACMAN_H_

#define CIMA 'w'
#define ESQUERDA 'a'
#define BAIXO 's'
#define DIREITA 'd'
#define BOMBA 'b'



int acabou ();
int validaDirecao(char);
int destinoFantasma(int, int, int *, int *);

void move(char direcao);
void fantasmas();
void explode();
void explode2(int, int, int, int, int);

#endif