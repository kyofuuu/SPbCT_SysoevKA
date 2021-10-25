/* Клиент */
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#define NAME "sfifo.cc"
int main()
{
    char text[80];
    int fd;
    printf("Ввести ссобщение\n");
    scanf(text);
    if ((fd = open(NAME, O_WRONLY)) == -1)
    {
        perror("Ошибка открытия клиента");
        return 1;
    }
    write(fd, text, strlen(text));
    close(fd);
    return 0;
}