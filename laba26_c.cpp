#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main()
{
    key_t key;
    struct mybuf
    {
        long mtype;
        char mtext[81];
    };
    struct mybuf buf;
    int fd;
    char text[81];
    int textLen;
    if ((key = ftok("server.c", 0)) == -1)
    {
        perror("Ошибка создания ключа");
        return 1;
    }
    if ((fd = msgget(key, 0)) == -1)
    {
        perror("Ошибка создания очереди");
        return 1;
    }
    if ((fd = msgrcv(fd, &buf, 80, 0, 0)) == -1)
    {
        perror("Ошибка приема сообщения");
        return 1;
    }
    printf("Получен текст -> %s\n", buf.mtext);
    return 0;
}