//Simulation of Cat>>f1 f2 command

#include <stdio.h>
#include<stdlib.h>

void main(int argc,char* argv[])
{
	FILE *fp1,*fp2;
	char ch;
	if(argc < 3)
	{
		printf("\nInsufficient number of Arguments\n");
		exit(1);
	}
	fp1 = fopen(argv[1],"r");
fp2 = fopen(argv[2],"r");
	if(fp2 == NULL)
	{
		printf("file name doesnt exist ");
		exit(1);
	}
	while ((ch = fgetc(fp2))!= EOF)
		fprintf(fp1,"%c",ch);
	fclose(fp1);
fclose(fp2);
}
