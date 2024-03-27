/*************************************************************************
	> File Name: 2.my_errno_test.c
	> Author: suyelu
	> Mail: suyelu@hotmail.com
	> Created Time: Wed 27 Mar 2024 01:17:26 PM CST
 ************************************************************************/

#include <stdio.h>
#include "my_errno.h"
int main() {
    if (open_heart(NULL) < 0) {
        my_perror("open_heart NULL");
    } 

    if (open_heart("/Lily") < 0) {
        fprintf(stderr, "open_heart /Lily : %s\n", my_strerror(my_errno));
    }

    if (open_heart("Lucy") < 0) {
        my_perror("open_heart Lucy");
    }
    
    return 0;
}
