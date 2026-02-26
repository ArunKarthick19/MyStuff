#include <stdio.h>
#include "mathlib.h"

int main()
{
    int number;

    scanf("%d", &number);

    int result = multiplyBy100(number);

    printf("%d\n", result);

    return 0;
}