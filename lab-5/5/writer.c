#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


#define FOREVER   1



int main(){
    int fd;
    char name[] = "aaa.fifo";

    (void)umask(0);
    mknod(name, S_IFIFO | 0666, 0);

    fd = open(name, O_WRONLY);

    while (FOREVER) {
        sleep(1);
        write(fd, "*", 1);
    }

    close(fd);

    return 0;
}
