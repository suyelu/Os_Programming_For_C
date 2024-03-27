/*************************************************************************
	> File Name: 1.errno_test.c
	> Author: suyelu
	> Mail: suyelu@hotmail.com
	> Created Time: Wed 27 Mar 2024 11:41:50 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
int main() {
    const char *msg = "Hello,errno!\n";
    //printf
    errno = 13;
    perror("Error");
    printf("Before system call : errno is %d\n", errno);
    ssize_t wsize = write(1, msg, strlen(msg));
    if (wsize < 0) {
        printf("After  system call : errno is %d\n", errno);
        perror("write");
    }
    wsize = write(3, msg, strlen(msg));
    if (wsize < 0) {
        fprintf(stderr, "write : %s\n", strerror(errno));
    }
    return 0;
}
