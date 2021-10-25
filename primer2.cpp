/* Сервер. Создает FIFO и ожидает сообщение */
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#define NAME "sfifo.cc"
int main()
{
    int fd; char buf[80];
    unlink(NAME);
    if (mkfifo(NAME, S_IFIFO | S_IRWXU | S_IRWXG | S_IRWXO))
    {
        perror("Ошибка FIFO"); return 1;
    }
    if ((fd = open(NAME, O_RDONLY)) == -1)
    {
        perror("Ошибка открытия файла сервера");
    }
    read(fd, buf, sizeof(buf));
    printf("Получено->\n", buf);
    close(fd);
    unlink(NAME); return 0;
}
