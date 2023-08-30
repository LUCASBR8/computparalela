/*
    Nome dos participantes do grupo:  
Andre Franco Raineri 321.636-81
Luana Miho Yasuda 421.486-77
Lucas Kenzo Kawamoto 421.456-51
*/

#include <stdio.h>

int acha(char st[],int target,int n){
  for (int i=0;i<=n;i++){
    if(st[i]==target){
      printf("o caracter esta %d posisao\n",i+1);
      return i+1;
    }
  }
  printf("o caracter esta não esta na string\n");
  return 0;
}

int main(void) {
  char st[]="ches";
  acha(st,'e',3);
}
