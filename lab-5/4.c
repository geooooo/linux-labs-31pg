#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>



int main(){
    int fd;
    int result;
    size_t size;
    char resstring[14];
    char name[] = "aaa.fifo";

    /* Права доступа файла FIFO должны соответствовать параметру mknod */
    (void)umask(0);
    mknod(name, S_IFIFO | 0666, 0); /* Создаем FIFO */

    result = fork(); /* Порождаем новый процесс */

    if (result > 0) {
        /* Родительский процесс. FIFO открываем на запись.*/
        fd = open(name, O_WRONLY);
        /* Запись в FIFO 14 байт */
        size = write(fd, "Hello, world!", 14);
        /*Закрываем входной поток данных. Родитель прекращает работу */
        close(fd);
        printf("Parent exit\n");}
    else {
        /* Порожденный процесс. Открываем FIFO на чтение.*/
        fd = open(name, O_RDONLY);
        /*Чтение из FIFO 14 байт в массив */
        size = read(fd, resstring, 14);
        /* Печатаем прочитанную строку */
        printf("%s\n ", resstring);
        /* Закрываем входной поток и завершаем работу */
        close(fd);
    }

    return 0;
}
