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

sprintf() :arrow_right: escrever uma palavra dentro de um array

strlen() :arrow_right: tamanho de um array de caracteres


### Anotações:

* Uso do scanf() - Sempre se usa o scanf(), para ler um único caracter, podemos ter problemas com os "enter's", um "enter" é considerado um caractere. O scanf() se perde quando são digitados uma letra e um enter. O enter fica de "buffer", e quando o scanf() é executado pela segunda vez, ele não solicita a letra, ele passa o enter como caractere direto. Para resolver isso, é necessário mudar um pouco a máscara. Ao invés de passar apenas o "%c", devemos passar " %c". O espaço diz ao scanf() para ignorar o enter e isso resolve o problema.