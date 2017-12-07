#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define IN                0
#define OUT               1
#define FOREVER           1
#define FILE_NAME_LEN    32



int main(){
    int fd[2];
    int pid;
    char file_name[FILE_NAME_LEN];

    if (pipe(fd) == -1) {
        printf("Ошибка pipe !\n");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == -1) {
        printf("Ошибка fork !\n");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        close(fd[IN]);
        while (FOREVER) {
            printf("Input new file name: ");
            scanf("%s", file_name);
            int file_name_len = strlen(file_name);
            write(fd[OUT], file_name, file_name_len);
            if (file_name_len == 0) {
                printf("Bye !\n");
                break;
            }
        }
        close(fd[OUT]);
    } else {;
        // Дочерний
        close(fd[OUT]);
        while (FOREVER) {
            size_t size = read(fd[IN], file_name, FILE_NAME_LEN);
            printf("%lu\n%s\n", size, file_name);
            if (size == 0) {
                break;
            }
            switch (fork()) {
                case -1: printf("Ошибка fork !\n");
                         exit(EXIT_FAILURE);
                case  0: close(fd[IN]);
                         close(fd[OUT]);
                         execlp("touch", "touch", file_name, NULL);
            }

        }
        close(fd[IN]);
    }

    return EXIT_SUCCESS;
}
