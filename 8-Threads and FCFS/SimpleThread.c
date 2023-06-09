//A simple Thread Program

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *threadfun();
int i,j,n;

void main()
{
	pthread_t T1;
	pthread_create(&T1,NULL,threadfun,NULL);
	printf("Inside Main Thread\n");
	for(i = 10;i<=15 ;i++)
	{
		printf("i = %d\n",i);sleep(1);
	}
}

void *threadfun()
{
	printf("Inside Thread\n");
	for(j = 1;j<=5;j++)
	{
		printf("j = %d\n",j);sleep(1);
	}
}
