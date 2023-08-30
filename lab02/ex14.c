/*
    Nome dos participantes do grupo:  
Andre Franco Raineri 321.636-81
Luana Miho Yasuda 421.486-77
Lucas Kenzo Kawamoto 421.456-51
*/

#include <stdio.h>

void insere(char* st, char c, int pos) {
  st[pos] = c; 
}

int main() {
  char str[100] = "hello";
  insere(str,'i',1);
  puts(str);
}
