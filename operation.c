#include "header.h"


int calculate(int *a, int *b, char operation) {

    switch (operation) {
        case '*':
        case '/':
        case '-':
        case '+':
        default:
            return *a + *b;
    }

}