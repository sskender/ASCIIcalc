#include "header.h"


int getDigitFromASCII(char *start, int WIDTH_MATRIX, int WIDTH_NUM, int HEIGHT_NUM) {

    int i, j, count_x;


    /*
     * 1 4 
     *
     * 1 has only one x in the first row
     * 4 has two x's
     * */
    count_x = 0;

    for(j = 0; j < WIDTH_NUM; j++) {
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
    i = HEIGHT_NUM / 2;

    for(j = 0; j < WIDTH_NUM; j++) {
        if( *(start+i*WIDTH_MATRIX+j) == 'x' ) {
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
    if( *(start+WIDTH_MATRIX+WIDTH_NUM-1) == 'x' && *(start+WIDTH_MATRIX) != 'x' ) {

        if( *(start+(HEIGHT_NUM/2+1)*WIDTH_MATRIX) == 'x' ) {
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
    if( *(start+WIDTH_MATRIX+WIDTH_NUM-1) != 'x' && *(start+WIDTH_MATRIX) == 'x' ) {

        if( *(start+(HEIGHT_NUM/2+1)*WIDTH_MATRIX) == 'x' && *(start+(HEIGHT_NUM/2+1)*WIDTH_MATRIX+WIDTH_NUM-1) == 'x' ) {
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
    if( *(start+(HEIGHT_NUM/2+1)*WIDTH_MATRIX) == 'x' && *(start+(HEIGHT_NUM/2+1)*WIDTH_MATRIX+WIDTH_NUM-1) == 'x' ) {
        return 8;
    }
    else if( *(start+(HEIGHT_NUM/2+1)*WIDTH_MATRIX) != 'x' && *(start+(HEIGHT_NUM/2+1)*WIDTH_MATRIX+WIDTH_NUM-1) == 'x' ) {
        return 9;
    }


    /*
     * not a number
     * */
    return -1;

}


void getASCIIFromDigit(char *start, int n, int WIDTH_MATRIX, int WIDTH_NUM, int HEIGHT_NUM) {}