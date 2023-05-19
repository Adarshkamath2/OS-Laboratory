#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#define Buffersize 100
int main()
{
	int fd1,fd2,n;
	char buffer[Buffersize], fname1[Buffersize], fname2[Buffersize] ;
	printf("Enter Copy Filename : ");
	scanf("%s",fname1);
	printf("Enter Moving Filename : ");
	scanf("%s",fname2);
	fd1 = open(fname1, O_RDWR);
	fd2 = open(fname2, O_RDWR);

	printf("File Descriptor 1 is %d\n",fd1);
	printf("File Descriptor 2 is %d\n",fd2);
	if(fd1==-1 || fd2 == -1)
	{
		printf("Failed to open File!\n");
		exit(0);
	}

	printf("Reading file 1...\n");
	n = read(fd1,buffer,100);
  
	printf("Writing in file 2...\n");
	write(fd2,buffer,n);
	printf("DONE\n");
	return 0;
}
