#include <stdio.h>

int main()
{
    int n;
    scanf("%d" , &n);
    int sign = n < 0 ? -1 : 1;
    if(-n > n)n = -n;
    int i;
    for(i = 1; i*i*i <= n ; i++)
    {
        if(i*i*i > n)break;
    }
    printf("%d" , sign * (i-1));
}