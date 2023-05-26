 //PRODUCER PROCESS
//Using shmget and shmat

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{
	void *psm;
	char buf[10];
	int shmid;
	
	shmid = shmget((key_t) 1122,1024,0666 | IPC_CREAT);
	printf("Key of Shared Memory : %d\n",shmid);
	
	psm = shmat(shmid,NULL,0666);
	printf("Memory attached at : %p\n",psm);
	printf("Enter Some Data to write to shared memory\n");
	read(0,buf,10);
	sprintf(psm,"%s",buf);
	
	shmdt(psm);
	return 0;	
}
