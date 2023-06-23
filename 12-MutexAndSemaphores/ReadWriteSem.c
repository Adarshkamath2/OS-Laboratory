
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>

sem_t wrt;


int cnt =1,numreader =0;
pthread_mutex_t mutex;

void* writer(void *wno)
{
	sem_wait(&wrt);
	cnt = cnt*2;
	//printf("Write %d Modified count to %d\n",*((int*)wno)),cnt);
	printf("Writer %d modified cnt to %d\n", (*((int *)wno)), cnt);
	sem_post(&wrt);
}

void* reader(void *rno)
{
	pthread_mutex_lock(&mutex);
	numreader++;
	if(numreader == 1)
	{
		sem_wait(&wrt);
	}
	pthread_mutex_unlock(&mutex);
	printf("Read %d : read cnt as %d\n",*((int*)rno),cnt);
	pthread_mutex_unlock(&mutex);
	numreader--;
	if(numreader == 0)
	{
		sem_post(&wrt);
	}
	pthread_mutex_unlock(&mutex);
} 

int main()
{
	pthread_t read[10],write[10];
	pthread_mutex_init(&mutex,NULL);
	sem_init(&wrt,0,1);
	
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	
	for(int i = 0;i<10;i++)
	{
		pthread_create(&read[i],NULL,(void*)reader,(void*)&a[i]);
	}
		
	for(int i = 0;i<5;i++)
	{
		pthread_create(&write[i],NULL,(void*)writer,(void*)&a[i]);
	}
		
	for(int i = 0;i<10;i++)
	{
		pthread_join(read[i],NULL);
	}
	for(int i = 0;i<5;i++)
	{
		pthread_join(write[i],NULL);
	}
	pthread_mutex_destroy(&mutex);
	sem_destroy(&wrt);
	return 0;
}
