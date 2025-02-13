#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int bottom_up_dp(int n, int *s, int *v, int C)
{
    //write your code here
   int dp[100][100] = {{0}};
    int included[100][100] = {{0}};

    // Compute the dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= C; j++) {
            if (s[i] <= j) {
                if (v[i] + dp[i - 1][j - s[i]] > dp[i - 1][j]) {
                    dp[i][j] = v[i] + dp[i - 1][j - s[i]];
                    included[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }



    return dp[n][C];
}


int main ()
{
    int n,C;
    int function;
    int *s;
    int *v;
    int i,j;
    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n+1));
    v = (int *) malloc(sizeof(int) * (n+1));

    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&s[i]);

    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);

    printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));

}
