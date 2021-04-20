#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MSET[1024];

int transform(int dig)
{
    int ans = 0;
    int c = 1;
    while(dig)
    {
        ans += (dig%2) * c;
        c <<= 1;
        dig /= 10;
    }
    return ans;
}

int main()
{
    int  n;
    scanf("%d%*c" , &n);
    for(int i = 0 ; i < 1024; i++)MSET[i] = 0;
    char query[10];
    while(n)
    {
        int temp;
        scanf("%s %d%*c" , &query , &temp);
        if(strcmp(query , "add") == 0)
        {
            MSET[transform(temp)]++;
        }
        if(strcmp(query , "delete") == 0)
        {
            MSET[transform(temp)]--;
        }
        if(strcmp(query , "query") == 0)
        {
            printf("%d\n",MSET[transform(temp)]);
        }
        n--;
    }
}