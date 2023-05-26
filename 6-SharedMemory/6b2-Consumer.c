//CONSUMER PROCESS P2
//using shmget and shmmat

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>

int main()
{
	void *psm;
	char buf[10];
	int shmid;
	
	shmid = shmget((key_t) 1122,1024,0666);
	printf("Key of Shared Memory : %d\n",shmid);
	
	psm = shmat(shmid,NULL,0666);
	printf("Process attached at : %p\n",psm);
	printf("Data Read from shared memory is : %s\n",(char*)psm);
	printf("\n");
	shmctl(shmid,IPC_RMID,NULL);
	return 0;	
}

