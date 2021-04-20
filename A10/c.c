#include <stdio.h>
#include <stdlib.h>

long long MOD = 1e9 + 7;
long long** dp;
int** arr;
int n;

int main()
{
    scanf("%d" , &n);
    arr = (int**)malloc(sizeof(int*) * n);
    dp = (long long**)malloc(sizeof(long long*) * n);
    for(int i = 0; i < n ; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * n);
        dp[i] = (long long*)malloc(sizeof(long long) * n);
        for (int j = 0; j < n; j++)
        {
            char c;
            scanf(" %c" , &c);
            arr[i][j] = c == '.';
            dp[i][j] = 0LL;
        }
    }

    dp[0][0] = arr[0][0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i][0])dp[i][0] = dp[i-1][0];
    }
    for(int j = 1; j < n; j++)
    {
        if(arr[0][j])dp[0][j] = dp[0][j-1];
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(arr[i][j])
            {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
            }
        }
    }
    printf("%lld" , dp[n-1][n-1]);

}