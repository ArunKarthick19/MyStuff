#include "mathlib.h"

int findFactorial(int n)
{
    if (n < 0)
        return -1;   // invalid

    if (n == 0 || n == 1)
        return 1;

    return n * findFactorial(n - 1);
}

int multiplyBy100(int n)
{
    return n * 100;
}