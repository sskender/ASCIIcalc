#include <stdio.h>
#include "header.h"


void printInputASCII(char *start, int WIDTH_MATRIX, int WIDTH_INPUT, int HEIGHT_NUM) {

    int i,j;

    printf("Input ASCII:\n");
    for(i = 0; i < HEIGHT_NUM; i++) {
        for(j = 0; j < WIDTH_INPUT; j++) {
            printf("%c", *(start+i*WIDTH_MATRIX+j) );
        }
        printf("\n");
    }
    printf("\n\n");

}


void scanInputASCII(char *start, int WIDTH_MATRIX, int WIDTH_INPUT, int HEIGHT_NUM) {

    int i,j;

    for(i = 0; i < HEIGHT_NUM; i++) {
        for(j = 0; j < WIDTH_INPUT; j++) {
            scanf("%c", (start+i*WIDTH_MATRIX+j) );
        }
    }

}