#include <stdio.h>
#include "header.h"

#define HEIGHT_NUMBER 7
#define WIDTH_NUMBER 5

#define MAX_WIDTH_INPUT 113     /* two 9 digit numbers with plus sign between */
#define MAX_WIDTH_OUTPUT 59     /* one 10 digit number */

#define MAX_NUMBERS 10          /* ten 1 digit numbers with plus sign between */


int main(void) {

    char input_ascii[HEIGHT_NUMBER][MAX_WIDTH_INPUT];
    char output_ascii[HEIGHT_NUMBER][MAX_WIDTH_OUTPUT];
    int  n, i, digit, output_number = 0, number = 0;


    /* input */
    scanf("%d", &n);
    scanASCII(&input_ascii[0][0], MAX_WIDTH_INPUT, n, HEIGHT_NUMBER);
    printASCII(&input_ascii[0][0], MAX_WIDTH_INPUT, n, HEIGHT_NUMBER);


    /* get number */
    for(i = 0; i < n; i = i + WIDTH_NUMBER + 1) {
        
        digit = getDigitFromASCII(&input_ascii[0][0]+i, MAX_WIDTH_INPUT, WIDTH_NUMBER, HEIGHT_NUMBER);

        if(digit != -1) {
            number = number * 10 + digit;
        }
        else {
            output_number = calculate(&output_number, &number, '+');
            number = 0;
        }
    }
    output_number = calculate(&output_number, &number, '+');


    /* convert back to ascii */

    printf("\nOUT: %d\n", output_number);

    return 0;
}