/*
    Nome dos participantes do grupo:
Andre Franco Raineri 321.636-81 Luana Miho Yasuda 421.486-77 Lucas Kenzo Kawamoto 421.456-51
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/wait.h>


int main(void) {
  int *shared_memory_variable1;
  int *shared_memory_variable2;
  int shmid;
  pid_t pid;
  shmid=shmget((key_t)1122,sizeof(int),0666|IPC_CREAT);

  shared_memory_variable1=(int *)shmat(shmid,NULL,0);
  *shared_memory_variable1=4;
  printf("PARENT: value = %d\n",*shared_memory_variable1);
  pid = fork();
   if (pid == 0) {
    shmid=shmget((key_t)1122,sizeof(int),0666);
    shared_memory_variable2=shmat(shmid,NULL,0);
    *shared_memory_variable2=*shared_memory_variable2+1;
    printf("CHILD: value=value+1 = %d\n",*shared_memory_variable2);
    return 0;
	}
	else if (pid > 0) {
		wait(NULL);
    printf("PARENT: value = %d\n",*shared_memory_variable1);
		return 0;
  }
}
