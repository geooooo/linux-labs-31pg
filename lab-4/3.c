#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void trigger_error(void);
void zombie_function(void);
void parent_function(void);



int main()
{
    switch (fork()) {
        case -1: trigger_error();
        case  0: zombie_function();
        default: parent_function();
    }

    return EXIT_SUCCESS;
}


void trigger_error(void)
{
    printf("Ошибка !\n");
    exit(EXIT_FAILURE);
}



void zombie_function(void)
{
    printf("zombie %d ready :}\n", getpid());
    exit(EXIT_SUCCESS);
}



void parent_function(void)
{
    // Убить из диспетчера задач или ctrl+C
    while (1) {
        sleep(1);
    }
    exit(EXIT_SUCCESS);
}
