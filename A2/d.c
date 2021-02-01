#include<stdio.h>
#include<stdlib.h>

const long long MOD = 1e9 + 7;

int main()
{
    int n,m;
    scanf("%d %d" , &n , &m);
    long long* P = (long long*)malloc(sizeof(long long) * n);
    long long* M = (long long*)malloc(sizeof(long long) * m);
    for(int i = 0 ; i < n ; i++)
        scanf("%lld" , &P[i]);
    for(int i = 0 ; i < m ; i++)
        scanf("%lld" , &M[i]);
    long long multiplier = 1;
    for(int i = 0 ; i < n-m+1 ; i++){
        if(i < m) multiplier *= M[i] , multiplier %= MOD;
        P[i] *= multiplier , P[i] %= MOD;
    }
    multiplier = 1;
    for(int i = n-1 ; i >= (n-m+1) ; i--)
    {
        multiplier *= M[m - n + i] , multiplier %= MOD;
        P[i] *= multiplier , P[i] %= MOD;
    }
    for(int i = 0 ; i < n ; i++)
        printf("%d " , P[i]);
}