#include <stdio.h>

void scanASCII(char *start, int MATRIX_WIDTH, int INPUT_WIDTH, int NUM_HEIGHT);
void printASCII(char *start, int MATRIX_WIDTH, int INPUT_WIDTH, int NUM_HEIGHT, FILE *dat_out);

int getDigitFromASCII(char *start, int MATRIX_WIDTH, int NUM_WIDTH, int NUM_HEIGHT);
void getASCIIFromDigit(char *start, int digit, int MATRIX_WIDTH, int NUM_WIDTH, int NUM_HEIGHT);