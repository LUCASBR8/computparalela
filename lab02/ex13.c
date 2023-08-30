/*
    Nome dos participantes do grupo:  
Andre Franco Raineri 321.636-81
Luana Miho Yasuda 421.486-77
Lucas Kenzo Kawamoto 421.456-51
*/

#include <stdio.h>

int remover(char st[],int target,int n){
  for(int i=target;i<n;i++){
    st[target]=st[target+1];
  }
  for (int i=0;i<n;i++){
    printf("%c",st[i]);
  }
  printf("\n");
  return 0;
}

int main(void) {
 
  char st[]="ches";
  remover(st,2,3);
  return 0;
}
