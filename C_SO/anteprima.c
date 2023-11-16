#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define DIM 50

int main(int argc, char const *argv[])
{
    int fd, pid, status, num;
    char nome[DIM];

    if (argc != 2)
    {
        printf(stderr, "Uso: %s <num>", argv[0]);
        exit(1);
    }

    if((num = atoi(argv[1])) <= 0){
        printf("%s deve esserer ", argv[1]);
        exit(2);
    }

    printf("Inserire il nome del ffile di cui vedere l'anteprimka:\n");
    scanf("%s", &nome);

    if ((fd = open(nome, O_RDONLY)) < 0)
    
    return 0;
}
