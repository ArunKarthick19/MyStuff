#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int m[MAX_SIZE];

int top_down_dp(int n)
{

     if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (m[n] != 0) // If the value is already computed, return it
        return m[n];

    // Compute the value of F(n) recursively
    m[n] = top_down_dp(n - 1) + 2 * top_down_dp(n - 2) - 3 * top_down_dp(n - 3);

    // Return the computed value of F(n)
    return m[n];
}



int main ()
{
    int n;
    int function;

    printf("Enter the value of n:\n");
    scanf("%d",&n);

    printf("The value of F(%d) is: %d \n", n, top_down_dp(n));

}
