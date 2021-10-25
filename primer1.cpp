#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
int main()
{
    pid_t childPid;
    int flds[2], status;
    char buf[] = "Message";
    // Создание канала
    if (pipe(flds) == -1)
    {
        perror("Pipe");
        exit(1);
    }
    // Ветвление процессов
    switch (childPid = fork())
    {
    case -1: perror("fork");
        exit(2);
    case 0: close(flds[0]); //Потомок
        printf("Child process %d\n", getpid());
        write(flds[1], buf, strlen(buf));
        close(flds[1]);
        exit(0);
    }
    // Процесс -родитель
    printf("Process %d\n", getpid());
    close(flds[1]);
    read(flds[0], buf, 80);
    printf("String -> %s\n", buf);
    close(flds[0]);
    wait(&status);
    return status;
}
