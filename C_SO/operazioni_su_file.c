#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    int fd;
    char buff[1024];
    if (argc != 2)
    {
        printf(stderr, "Uso: %s nomefile>", argv[0]);
        exit(1);
    }

    // permessi 0644 rw-r--r--
    fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd < 0)
    {
        fprintf(stderr, "Error creating file %s\n", argv[1]);
        exit(2);
    }

    // fgets(fa una scanf di una stringa)
    printf("Inserire una stringa:\n");
    fgets(buff, 1024, stdin);

    while (strcmp(buff, "fine\n") != 0)
    {
        write(fd, buff, strlen(buff));
        printf()
            printf
    }

    return 0;
}