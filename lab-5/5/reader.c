#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


#define FOREVER     1
#define BUF_LEN    32



int main(){
    int fd;
    char name[] = "aaa.fifo";
    size_t size;
    char buf[BUF_LEN];

    (void)umask(0);
    mknod(name, S_IFIFO | 0666, 0);

    fd = open(name, O_RDONLY);

    while (FOREVER) {
        size = read(fd, buf, BUF_LEN);
        printf("%s", buf);
        fflush(stdout);
    }

    close(fd);

    return 0;
}
