/*************************************************************************
	> File Name: my_errno.c
	> Author: suyelu
	> Mail: suyelu@hotmail.com
	> Created Time: Wed 27 Mar 2024 01:09:23 PM CST
 ************************************************************************/

#include <stdio.h>
#include "my_errno.h"

int my_errno;

int open_heart(const char *name) {
    if (name == NULL) {
        my_errno = MY_HEART_LOCKED;
        return -1;
    } else if (name[0] == '/') {
        my_errno = MY_NO_ACCESS;
        return -1;
    } else {
        my_errno = MY_SUCCESS;
        return 0;
    }
}

const char *my_strerror(int my_errno) {
    switch (my_errno) {
        case MY_SUCCESS:
            return "Heart Opened successfully";
        case MY_NO_ACCESS:
            return "No access to her heart";
        case MY_HEART_LOCKED:
            return "Her Heart is locked";
        default:
            return "Unknown feeling";
    }
}

void my_perror(const char * prefix) {
    if (prefix != NULL) {
        fprintf(stderr, "%s: %s\n", prefix, my_strerror(my_errno));
    } else {
        fprintf(stderr, "%s\n", my_strerror(my_errno));
    }
}
