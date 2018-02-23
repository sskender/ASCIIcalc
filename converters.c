#include "header.h"


int i, j;


int getDigitFromASCII(char *start, int MATRIX_WIDTH, int NUM_WIDTH, int NUM_HEIGHT) {

    int count_x;


    /*
     * 1 4 
     *
     * 1 has only one x in the first row
     * 4 has two x's
     * */
    count_x = 0;

    for(j = 0; j < NUM_WIDTH; j++) {
        if( *(start+j) == 'x' ) {
            count_x++;
        }
    }

    switch (count_x) {
        case 1:
            return 1;
        case 2:
            return 4;
        default:
            break;
    }


    /*
     * 0 7 
     *
     * 0 has two x's in the middle
     * 7 has only one on the right side
     * */
    count_x = 0;

    for(j = 0; j < NUM_WIDTH; j++) {
        if( *(start+(NUM_HEIGHT/2)*MATRIX_WIDTH+j) == 'x' ) {
            count_x++;
        }
    }

    switch (count_x) {
        case 2:
            return 0;
        case 1:
            return 7;
        default:
            break;
    }


    /*
     * 2 3
     *
     * 2 and 3 have x in the second row on the right side
     * 2 has x in the row after middle on the left side
     * 3 has x in the row after middle on the right side, but not on the left side
     * */
    if( *(start+MATRIX_WIDTH+NUM_WIDTH-1) == 'x' && *(start+MATRIX_WIDTH) != 'x' ) {

        if( *(start+(NUM_HEIGHT/2+1)*MATRIX_WIDTH) == 'x' ) {
            return 2;
        }
        else {
            return 3;
        }

    }


    /* 
     * 5 6 
     *
     * 5 and 6 have x in the second row on the left side
     * 5 has x in the row after middle on the right side, but not on the left side
     * 6 has x's in the row after middle on both sides
     * */
    if( *(start+MATRIX_WIDTH+NUM_WIDTH-1) != 'x' && *(start+MATRIX_WIDTH) == 'x' ) {

        if( *(start+(NUM_HEIGHT/2+1)*MATRIX_WIDTH) == 'x' && *(start+(NUM_HEIGHT/2+1)*MATRIX_WIDTH+NUM_WIDTH-1) == 'x' ) {
            return 6;
        }
        else {
            return 5;
        }

    }


    /*
     * 8 9
     *
     * those are only numbers left so only fifth row has to be checked
     * 8 has x's on both sides
     * 9 has x only on the right side
     * */
    if( *(start+(NUM_HEIGHT/2+1)*MATRIX_WIDTH) == 'x' && *(start+(NUM_HEIGHT/2+1)*MATRIX_WIDTH+NUM_WIDTH-1) == 'x' ) {
        return 8;
    }
    else if( *(start+(NUM_HEIGHT/2+1)*MATRIX_WIDTH) != 'x' && *(start+(NUM_HEIGHT/2+1)*MATRIX_WIDTH+NUM_WIDTH-1) == 'x' ) {
        return 9;
    }


    /*
     * not a number
     * */
    return -1;

}


void getASCIIFromDigit(char *start, int digit, int MATRIX_WIDTH, int NUM_WIDTH, int NUM_HEIGHT) {

    /*
     * first row
     * last row
     */
    for(j = 0; j < NUM_WIDTH; j++) {
        *(start+j) = 'X';
        *(start+(NUM_HEIGHT-1)*MATRIX_WIDTH+j) = 'X';
    }


    switch (digit) {

        case 1:
            *start = '.';

        case 4:
            for(j = 1; j < NUM_WIDTH-1; j++) {
                *(start+j) = '.';
            }

        case 7:
            for(j = 0; j < NUM_WIDTH-1; j++) {
                *(start+(NUM_HEIGHT-1)*MATRIX_WIDTH+j) = '.';
            }
            break;

        default:
            break;

    }


    /*
     * middle row
     */
    for(j = 0; j < NUM_WIDTH; j++) {
        *(start + (NUM_HEIGHT/2)*MATRIX_WIDTH + j) = 'X';
    }

    if(digit == 0 || digit == 1 || digit == 7) {
        for(j = 0; j < NUM_WIDTH-1; j++) {
            *(start + (NUM_HEIGHT/2)*MATRIX_WIDTH + j) = '.';
        }
        if(digit == 0) {
            *(start + (NUM_HEIGHT/2)*MATRIX_WIDTH) = 'X';
        }
    }


    /*
     * top
     */
    for(i = 1; i < NUM_HEIGHT/2; i++) {
        for(j = 0; j < NUM_WIDTH; j++) {

            *(start+i*MATRIX_WIDTH+j) = '.';

            if(j == 0) {
                switch (digit) {
                    case 1:
                    case 2:
                    case 3:
                    case 7:
                        break;

                    default:
                        *(start+i*MATRIX_WIDTH+j) = 'X';
                        break;
                }
            }
            else if(j == NUM_WIDTH-1) {
                switch (digit) {
                    case 5:
                    case 6:
                        break;

                    default:
                        *(start+i*MATRIX_WIDTH+j) = 'X';
                        break;
                }
            }

        }
    }


    /*
     * bottom
     */
    for(i = NUM_HEIGHT/2+1; i < NUM_HEIGHT-1; i++) {
        for(j = 0; j < NUM_WIDTH; j++) {

            *(start+i*MATRIX_WIDTH+j) = '.';

            if(j == 0) {
                switch (digit) {
                    case 1:
                    case 3:
                    case 4:
                    case 5:
                    case 7:
                    case 9:
                        break;

                    default:
                        *(start+i*MATRIX_WIDTH+j) = 'X';
                        break;
                }
            }
            else if(j == NUM_WIDTH-1 && digit != 2) {
                *(start+i*MATRIX_WIDTH+j) = 'X';
            }

        }
    }


    /*
     * space on the right side
     */
    for(i = 0; i < NUM_HEIGHT; i++) {
        *(start+i*MATRIX_WIDTH+NUM_WIDTH) = '.';
    }


}