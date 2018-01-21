#include "header.h"


int getNumberFromASCII(char *start, int WIDTH_NUMBER) {
    int i, j, count_x;


    /*
     * 1 4 
     *
     * 1 has only one x in the first row
     * 4 has two x's
     * */
    count_x = 0;
    for(j = 0; j < WIDTH_NUMBER; j++) {
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
     * 0 has two x's in the fourth row
     * 7 has only one on the right side
     * */
    count_x = 0;
    i = 3;
    for(j = 0; j < WIDTH_NUMBER; j++) {
        if( *(start+i*WIDTH_NUMBER+j) == 'x' ) {
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
     * 2 has x in the fifth row on the left side
     * 3 has x in the fifth row on the right side, but not on the left side
     * */
    if( *(start+2*WIDTH_NUMBER-1) == 'x' && *(start+WIDTH_NUMBER) != 'x' ) {

        if( *(start+4*WIDTH_NUMBER) == 'x' ) {
            return 2;
        } else {
            return 3;
        }

    }


    /* 
     * 5 6 
     *
     * 5 and 6 have x in the second row on the left side
     * 5 has x in the fifth row on the right side, but not on the left side
     * 6 has x's in the fifth row on both sides
     * */
    if( *(start+2*WIDTH_NUMBER-1) != 'x' && *(start+WIDTH_NUMBER) == 'x' ) {

        if( *(start+4*WIDTH_NUMBER) == 'x' && *(start+5*WIDTH_NUMBER-1) == 'x' ) {
            return 6;
        } else {
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
    if( *(start+5*WIDTH_NUMBER-1) == 'x' && *(start+4*WIDTH_NUMBER) == 'x' ) {
        return 8;
    } else {
        return 9;
    }

}
