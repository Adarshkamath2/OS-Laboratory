// To generate and print fibonacci series using shm_open and  mmap
// parent

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char *argu[])
{
    int i, k, n1, n2, n3;
    pid_t pid;
    const int SIZE = 4096;
    int shm_fd;
    void *ptr;

    if (argc > 1)
    {
        sscanf(argu[1], "%d", &i);
        if (i < 1)
        {
            printf("error input:%d\n", i);
            return 0;
        }
    }
    else
    {
        printf("Error:not passing N i commandline \n");
        exit(0);
    }
    pid = fork();
    if (pid == 0)
        execlp("./fif", "fif", argu[1], NULL);
    else if (pid > 0)
    {
        wait(NULL);
        printf("\nParent:child completed\n");

        shm_fd = shm_open("OS", O_RDONLY, 0666);
        ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
        printf("Parent printing :\n");
        printf("%s", (char *)ptr);
        shm_unlink("OS");
    }
    return 0;
}
