#include <stdio.h>
#include <math.h>
#include "header.h"

#define NUM_HEIGHT 7
#define NUM_WIDTH 5

#define MAX_WIDTH_INPUT 113     /* two 9 digit numbers with plus sign between */
#define MAX_WIDTH_OUTPUT 59     /* one 10 digit number */


int main(void) {

    char input_ascii[NUM_HEIGHT][MAX_WIDTH_INPUT];
    char output_ascii[NUM_HEIGHT][MAX_WIDTH_OUTPUT];

    int input_len, output_len;
    int num_sol = 0, num_sol_bkp, num_sol_len = 0, num_sol_len_bkp = 0;
    int i, digit, num_temp = 0;
    
    FILE *dat_out = fopen("output.txt", "w");
    char *start = &input_ascii[0][0];


    /*
     * Input:
     * 1) input len
     * 2) whole matrix row by row
     */
    scanf("%d", &input_len);
    scanASCII(start, MAX_WIDTH_INPUT, input_len, NUM_HEIGHT);


    /*
     * calculate equation
     */
    for(i = 0; i < input_len; i = i + NUM_WIDTH + 1) {

        digit = getDigitFromASCII(start+i, MAX_WIDTH_INPUT, NUM_WIDTH, NUM_HEIGHT);

        if(digit != -1) {
            num_temp = num_temp * 10 + digit;
        }
        else {
            num_sol += num_temp;
            num_temp = 0;
        }
    }
    num_sol += num_temp;


    /* get number of digits required to display solution */
    num_sol_bkp = num_sol;
    while(num_sol_bkp) {
        num_sol_len++;
        num_sol_len_bkp++;
        num_sol_bkp /= 10;
    }


    /* fill matrix with each digit */
    start = &output_ascii[0][0];
    for(i = 0; i < num_sol_len; i++) {

        digit = num_sol / (int)pow(10,num_sol_len_bkp-1) % 10;
        getASCIIFromDigit(start, digit, MAX_WIDTH_OUTPUT, NUM_WIDTH, NUM_HEIGHT);

        num_sol_len_bkp--;
        start += NUM_WIDTH + 1;

    }


    /*
     * display ascii and save to file
     * (minus one to remove last column of dots)
     */
    output_len = num_sol_len * (NUM_WIDTH + 1) - 1;
    printASCII(&output_ascii[0][0], MAX_WIDTH_OUTPUT, output_len, NUM_HEIGHT, dat_out);

    fclose(dat_out);

    return 0;
}