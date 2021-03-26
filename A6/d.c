#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,k,x;
    scanf("%d %d %d%*c" , &N , &k , &x);
    int* students = (int*)malloc(sizeof(int) * N);
    int* fact = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%*c" , &students[i]);
        fact[i] = 1;
    }
    int* r = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d%*c" , &r[i]);
    }
    for (int i = 0; i < k; i++)
    {
        fact[r[i]] = 0;
    }
    int ans1 = 0;
    for (int i = 0; i < N; i++)
    {
        ans1 += students[i] * fact[i];
    }
    printf("%d " , ans1);

    int fullSum = 0;
    int currSum = 0;
    for (int i = 0; i < x; i++)
    {
        fullSum += students[i];
        currSum += students[i] * fact[i];
    }
    int ans2 = fullSum - currSum;
    
    for(int i = x ; i < N ; i++)
    {
        fullSum += students[i];
        fullSum -= students[i - x];

        currSum += students[i] * fact[i];
        currSum -= students[i - x] * fact[i-x];

        if((fullSum - currSum) > ans2)   
            ans2 = fullSum - currSum;

    }

    printf("%d" , ans1+ans2);

    
}