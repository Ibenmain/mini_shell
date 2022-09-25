#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int a = 0;

int main()
{
    signal(SIGINT, handle_sigint);
    while (1)
    {
        print();
        printf("hello\n");
        sleep(1);
    }
    return 0;
}