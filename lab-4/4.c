#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char** argv, char** env)
{
    execvp("env", env);

    return EXIT_SUCCESS;
}
