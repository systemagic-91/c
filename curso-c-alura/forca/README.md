# Jogo de Forca em C

Linguagem C - Modulo II

* operadores logicos
* funções
* arrays
* ponteiros e endereços de memória
* entrada e saída
* arquivos
* header files

### Bibliotecas:

string.h :arrow_right: fornece funções, macros e definições da biblioteca padrão da linguagem de programação C para manipulação de cadeias de caracteres e regiões de memória. As funções trabalham apenas com cadeias de caracteres ASCII, mas não são compatíveis com Unicode.

### Funções:

sprintf() :arrow_right: escrever uma palavra dentro de um array.

strlen() :arrow_right: tamanho de um array de caracteres.

fopen() :arrow_right: abre um arquivo de um diretório qualquer e devolve um ponteiro de arquivo (tipo FILE).

fclose() :arrow_right: fecha o arquivo aberto.

fscanf() :arrow_right: leitura de um arquivo.

fprintf() :arrow_right: escrita de um arquivo.

fseek() :arrow_right: posicionar cabeçote de leitura e escrita no arquivo.

feof() :arrow_right: verifica se o cabeçote esta apontando para o fim do arquivo.

### Anotações:

* Uso do scanf() - Sempre se usa o scanf(), para ler um único caracter, podemos ter problemas com os "enter's", um "enter" é considerado um caractere. O scanf() se perde quando são digitados uma letra e um enter. O enter fica de "buffer", e quando o scanf() é executado pela segunda vez, ele não solicita a letra, ele passa o enter como caractere direto. Para resolver isso, é necessário mudar um pouco a máscara. Ao invés de passar apenas o "%c", devemos passar " %c". O espaço diz ao scanf() para ignorar o enter e isso resolve o problema.

* Temos o costume de colocar as assinaturas das funções que vão ser implementadas no nosso programa em um arquivo separado. Esse arquivo é conhecido como header file e tem a extensão .h. Para incluir ele usamos: #include "file.h" (atenção para aspas, elas indicam que o arquivo é nosso e está no diretório corrente).