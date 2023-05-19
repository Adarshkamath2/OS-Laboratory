//Fork Process

#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("Before Fork : \n");
	fork();
	printf("After First Fork : \n");
	fork();
	printf("After Second Fork : \n");
	fork();
	printf("After Third Fork : \n");
	return 0;
}
