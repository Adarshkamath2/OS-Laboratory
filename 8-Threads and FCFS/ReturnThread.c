//Example Program for returning Thread

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void *sum(void* arg);

int sm = 0;
int a[5] = {1,2,3,4,5};
void *res;
void main(int argc,char *argv[])
{
	pthread_t T1;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&T1,&attr,sum,(void*)a);
	pthread_join(T1,&res);
	
	printf("Inside Main Thread\n");
	printf("Sum = %d\n",sm);
	printf("Thread returned : %s\n",(char*)res);
}

void *sum(void *parm)
{
	int i,n;
	int *x = parm;
	n = atoi(parm);
	printf("Inside Sum Thread\n");
	for(i = 0;i<=5;i++)
	{
		sm += x[i];
	}
	pthread_exit("Sum Calculated");
}
