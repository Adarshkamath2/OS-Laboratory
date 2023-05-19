//program to simulate exit getpid etc

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t child_pid,my_pid,parent_pid,wid;
	int i =10;
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
		printf("[CHILD] i =  %d\n",--i);
		printf("[CHILD] Child Process going to load another program using execlap syscall\n");
		execlp("/bin/pwd","pwd",NULL);
	}
	else
	{
		//Parent Process
		printf("[PARENT] This is a PARENT process \n");
		my_pid = getpid();
		parent_pid = getppid();
		printf("[PARENT] My pid : %d\n",my_pid);
		printf("[PARENT] Waiting for child to Terminate\n");
		wid = wait(NULL);
		printf("[PARENT] Resuming after the Termination of %d\n",wid);
		printf("[PARENT] My Parents pid : %d\n",parent_pid);
		printf("[PARENT] My Childs pid : %d\n",child_pid);
		printf("[PARENT] i = %d\n",++i);
	}
	return 0;
}
