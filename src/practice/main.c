extern int errno;
#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>



int main(int argc, char *const *argv){
    char    **arr;

    arr = malloc(sizeof(char *) * 4);

    arr[0] = malloc(sizeof(char) * 60);
    arr[1] = malloc(sizeof(char) * 60);
    arr[2] = malloc(sizeof(char) * 60);
    arr[3] = NULL;

    free_arr2d(arr);
}