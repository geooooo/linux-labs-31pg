#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define IN                0
#define OUT               1
#define FOREVER           1
#define FILE_NAME_LEN    32
#define MSG_LEN          32



int main(){
    int fd_pc[2];
    int fd_cp[2];
    int pid;
    char msg[MSG_LEN];
    char file_name[FILE_NAME_LEN];

    if (pipe(fd_pc) == -1) {
        printf("Ошибка pipe !\n");
        exit(EXIT_FAILURE);
    }

    if (pipe(fd_cp) == -1) {
        printf("Ошибка pipe !\n");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == -1) {
        printf("Ошибка fork !\n");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        close(fd_pc[IN]);
        close(fd_cp[OUT]);
        while (FOREVER) {
            printf("Input new file name: ");
            scanf("%s", file_name);
            int file_name_len = strlen(file_name);
            write(fd_pc[OUT], file_name, file_name_len);
            if (file_name_len == 0) {
                printf("Bye !\n");
                break;
            }
            size_t size = read(fd_cp[IN], msg, MSG_LEN);
            printf("# %s\n", msg);
        }
        close(fd_pc[OUT]);
        close(fd_cp[IN]);
    } else {;
        // Дочерний
        while (FOREVER) {
            size_t size = read(fd_pc[IN], file_name, FILE_NAME_LEN);
            printf("%lu\n%s\n", size, file_name);
            if (size == 0) {
                break;
            }
            switch (fork()) {
                case -1: printf("Ошибка fork !\n");
                         exit(EXIT_FAILURE);
                case  0: write(fd_cp[OUT], "Create new file...", strlen("Create new file..."));
                         execlp("touch", "touch", file_name, NULL);
            }
        }
    }

    return EXIT_SUCCESS;
}
