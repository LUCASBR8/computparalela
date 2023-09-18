#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/wait.h>


int main(void) {
  int *shared_memory1;
  int *shared_memory2;
  int shmid;
  pid_t pid;
  shmid=shmget((key_t)1122,sizeof(int),0666|IPC_CREAT);

  shared_memory1=(int *)shmat(shmid,NULL,0);
  *shared_memory1=4;
  printf("PARENT: value = %d\n",*shared_memory1);
  pid = fork();
   if (pid == 0) {
    shmid=shmget((key_t)1122,sizeof(int),0666);
    shared_memory2=shmat(shmid,NULL,0);
    *shared_memory2=*shared_memory2+1;
    printf("CHILD: value=value+1 = %d\n",*shared_memory2);
    return 0;
	}
	else if (pid > 0) {
		wait(NULL);
    printf("PARENT: value = %d\n",*shared_memory1);
		return 0;
  }
}
