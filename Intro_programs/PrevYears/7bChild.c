/*      C program to generate and print Fibonacci series using system calls: stmget() and shmat()
        Name of the program: ChildFib2.c
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
    int k = 0, n1 = 0, n2 = 1, n3, i;
    void *ptr;
    int shmid = shmget((key_t)1122, 4096, 0666);
    ptr = shmat(shmid, NULL, 0666);
    printf("CHILD:\n");
    i = atoi(argv[1]);
    while (k != i)
    {
        sprintf(ptr, " %d ", n1);
        printf("%d", n1);
        n3 = n1 + n2;
        ptr += strlen(ptr);
        k++;
    }
    shmdt(shmid);
    return 0;
}
