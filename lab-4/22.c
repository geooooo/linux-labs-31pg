#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void trigger_error(void);
void child_function(void);
void parent_function(void);



int main()
{
    switch (fork()) {
        case -1: trigger_error();
        case  0: child_function();
        default: parent_function();
    }

    return EXIT_SUCCESS;
}


void trigger_error(void)
{
    printf("Ошибка !\n");
    exit(EXIT_FAILURE);
}



void child_function(void)
{
    printf("child_function ...\n");
    exit(EXIT_SUCCESS);
}



void parent_function(void)
{
    printf("parent_function ...\n");
    exit(EXIT_SUCCESS);
}
