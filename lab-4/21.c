#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_A   10
#define DELAY   1



int main()
{
    pid_t pid = fork();

    for (int a = 0; a < MAX_A; a += (pid == 0)? 2 : 3) {
        sleep(DELAY);
        printf("%d ", a);
        fflush(stdout);
    }

    return EXIT_SUCCESS;
}
