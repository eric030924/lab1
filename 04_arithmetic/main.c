#include <stdio.h>
#include "calc.h"

int main(void)
{
    double a = 10.0;
    double b = 3.0;

    printf("Add: %.2f\n", add(a, b));
    printf("Subtract: %.2f\n", subtract(a, b));
    printf("Multiply: %.2f\n", multiply(a, b));

    if (b != 0)
        printf("Divide: %.2f\n", divide(a, b));
    else
        printf("Cannot divide by zero.\n");

    return 0;
}
