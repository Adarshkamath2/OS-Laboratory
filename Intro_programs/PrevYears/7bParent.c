/*  C program to generate and print fibonacci series using system calls: shmget() and shmat()
    Name of the program: fibParent2.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, k, n1 = 0, n2 = 1, n3;
    pid_t pid;
    const int SIZE = 4096;
    int shmid;
    void *ptr;
    shmid = shmget((key_t)1122, 4096, 0666 | IPC_CREAT);
    ptr = shmat(shmid, NULL, 0666);
    if (argc > 1)
    {
        sscanf(argv[1], "%d", &i);
        if (i < 1)
        {
            printf("Error input: %d\n", i);
            return 0;
        }
    }
    else
    {
        return 1;
    }

    if (pid == 0)
    {
        execlp("./fib", "fib", argv[1], NULL);
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("\nParent: Child completed\n");
        printf("Parent printing: \n");
        printf("%s", (char *)ptr);
        shmdt(shmid);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}
