#include<stdio.h>
void main()
{
	char fn[10];
	printf("Enter Filename : ");
	scanf("%s",fn);
	if(remove(fn)==0)
		printf("File Removed...\n");
	else
		printf("File Cannot be Removed...\n");
}
