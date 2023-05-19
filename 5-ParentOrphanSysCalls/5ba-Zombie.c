//program to demonstrate the creation of zombie process

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

void main()
{
	pid_t child_pid,my_pid,parent_pid,wid;
	child_pid = fork();
	if(child_pid < 0)
	{
		printf("Fork Failed..Exiting!!\n");
		exit(0);
	}
	if(child_pid == 0)
	{
		//Child Process
		printf("[CHILD] This is a CHILD process \n");
		my_pid = getpid();
		parent_pid = getppid();
		printf("[CHILD] My pid : %d\n",my_pid);
		printf("[CHILD] My parents pid : %d\n",parent_pid);
		printf("[CHILD] Exitting...\n");
		exit(0);
	}
	//Parent Process
		printf("[PARENT] This is a PARENT process \n");
		my_pid = getpid();
		parent_pid = getppid();
		printf("[PARENT] My pid : %d\n",my_pid);
		printf("[PARENT] My parents pid : %d\n",parent_pid);
		printf("[PARENT] Sleeping for 10 seconds..\n");
		sleep(100);
		printf("[PARENT] Childs pid : %d\n has ended, but it has an entry in process table. It is a Zombie process.\n",child_pid);

}
