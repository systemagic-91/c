# Jogo de PACMAN em C

Linguagem C - Modulo III

* funções recursivas
* manipulação de matrizes
* definição de tipos
* estruturas (structs)
* diretivas de compilação
* divisão de codigo em arquivos

### Bibliotecas:

:arrow_right: 

### Funções:

malloc() :arrow_right: aclocação dinamica de memoria.

free() :arrow_right: liberação da memoria alocada.

sizeof() :arrow_right: retorna quantos bytes um inteiro, char ou struct precisa.

strcpy() :arrow_right: copia um array de char para outro.

memcpy() :arrow_right: copia o que esta na memoria (copiar structs).

memset() :arrow_right: inicializar structs ou arrays com valor padrão.


### Anotações:

* Se quiséssemos um ponteiro para apontar para uma matriz como um todo? Matrizes são ponteiros que apontam para outros ponteiros, a declaração é int**, ou seja, duas estrelas para representar "ponteiro de ponteiro". Lembrando que ponteiros guardam ENDEREÇOS DE MEMÓRIA então um "ponteiro de ponteiro" guarda o endereço de memória (onde ele está na memória) de outro ponteiro.

* ifndef é uma diretiva de compilação usada para verificar se uma constante (define) não foi previamente definido.