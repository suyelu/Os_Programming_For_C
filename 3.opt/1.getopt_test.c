/*************************************************************************
	> File Name: 1.getopt_test.c
	> Author: suyelu
	> Mail: suyelu@hotmail.com
	> Created Time: Wed 27 Mar 2024 02:24:40 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//选项字符串  a:b::cd
//
//
char *name = NULL;
int age = 18;
char *gender = "男";

int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "n:a:g:")) != -1) {
        switch (opt) {
            case 'n':
                name = optarg;
                break;
            case 'a':
                age = atoi(optarg);
                break;
            case 'g':
                gender = optarg;
                break;
            default:
                fprintf(stderr, "Usage : %s -n name -a age -g gender!\n", argv[0]);
                return 1;
        }
    }
    printf("optind : %d, argv[%d] = %s, argv[%d] = %s\n", optind, optind, argv[optind],\
          optind + 1, argv[optind + 1]);
    printf("Name : %s\n", name);
    printf("Age : %d\n", age);
    printf("Gender: %s\n", gender);
    return 0;
}

