#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    int fd, pid, status, i;

    if (argc < 3)
    {
        printf(stderr, "Uso: %s nomefile>", argv[0]);
        exit(1);
    }

    fd = open("conteggio.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        fprintf(stderr, "Error creating file %s\n", "conteggio.txt");
        exit(2);
    }

    close(fd);

    // creo il processo figlio
    for (i = 2; i < argc; i++)
    {
        pid = fork();
        if (pid < 0)
        {

            perror("Fork andata male");
            exit(3);
        }
        if (pid == 0)
        {
            // child process
            char log[256];
            /*apro il file in append*/
            fd = open("conteggio.txt", O_WRONLY | O_APPEND);
            /*creo il log dell'operazione di conteggio*/
            sprintf(log, "%s %s\n", argv[1], argv[i]);
            /*scrivo il log su file*/
            write(fd, log, strlen(log));
            /*chiudo il file*/
            close(fd);

            printf("\n Num di righe in cui compare la stringa %s:\n", argv[i]);
            execlp("grep", "grep", "-c", argv[i], argv[1], NULL);

            perror("exec");
            exit(4);
        }
    }

    for (i = 2; i < argc; i++)
    {
        wait(&status);
    }

    return 0;
}
