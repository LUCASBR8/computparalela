#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/wait.h>


int main(void) {
  int *a;
  int shmid;
  pid_t pid;
  shmid=shmget((key_t)1122,sizeof(int),0666|IPC_CREAT);

  a=(int *)shmat(shmid,NULL,0);
  *a=4;
  printf("PARENT: value = %d\n",*a);
  pid = fork();
   if (pid == 0) {
    shmid=shmget((key_t)1122,sizeof(int),0666);
    a=shmat(shmid,NULL,0);
    *a=*a+1;
    printf("CHILD: value=value+1 = %d\n",*a);
    return 0;
	}
	else if (pid > 0) {
		wait(NULL);
    printf("PARENT: value = %d\n",*a);
		return 0;
  }
}
