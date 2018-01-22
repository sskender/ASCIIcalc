#include <stdio.h>
#include "header.h"


void printASCII(char *start, int WIDTH_MATRIX, int WIDTH_INPUT, int HEIGHT_NUM) {

    int i,j;

    printf("ASCII:\n");
    for(i = 0; i < HEIGHT_NUM; i++) {
        for(j = 0; j < WIDTH_INPUT; j++) {
            printf("%c", *(start+i*WIDTH_MATRIX+j) );
        }
        printf("\n");
    }
    printf("\n\n");

}


void scanASCII(char *start, int WIDTH_MATRIX, int WIDTH_INPUT, int HEIGHT_NUM) {

    int i,j;

    for(i = 0; i < HEIGHT_NUM; i++) {
        for(j = 0; j < WIDTH_INPUT; j++) {
            scanf("%c", (start+i*WIDTH_MATRIX+j) );
        }
    }

}