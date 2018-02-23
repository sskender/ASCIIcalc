#include <stdio.h>
#include "header.h"

int i, j;


void printASCII(char *start, int MATRIX_WIDTH, int INPUT_WIDTH, int NUM_HEIGHT, FILE *dat_out) {

    printf("\n");
    fprintf(dat_out, "%d", INPUT_WIDTH);
    
    for(i = 0; i < NUM_HEIGHT; i++) {
        for(j = 0; j < INPUT_WIDTH; j++) {

            printf("%c", *(start+i*MATRIX_WIDTH+j) );
            fprintf(dat_out, "%c", *(start+i*MATRIX_WIDTH+j) );
            
        }
        printf("\n");
    }
    printf("\n");

}


void scanASCII(char *start, int MATRIX_WIDTH, int INPUT_WIDTH, int NUM_HEIGHT) {

    for(i = 0; i < NUM_HEIGHT; i++) {
        for(j = 0; j < INPUT_WIDTH; j++) {
            scanf("%c", (start+i*MATRIX_WIDTH+j) );
        }
    }

}