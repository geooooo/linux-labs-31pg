#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define IN    0
#define OUT   1



int main(){
    int fd[2];
    unsigned long long size;
    char* data = "*";
    int pid;

    if (pipe(fd) == -1) {
        printf("Ошибка pipe !\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        ;
    } else {
        close(fd[IN]);
        for (size = 0; write(fd[OUT], data, 1); ++size) ;
        close(fd[OUT]);
    }

    printf("unsigned long long size = %lu\n", sizeof(unsigned long long));
    printf("Pipe size = %llu\n", size);

    return EXIT_SUCCESS;
}
