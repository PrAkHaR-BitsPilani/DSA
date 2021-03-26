#include <stdlib.h>
#include <stdio.h>

int max(int a , int b)
{
    if(a > b)return a;
    return b;
}
int min(int a , int b)
{
    if(a < b)return a;
    return b;
}

int main()
{
    int n;
    scanf("%d%*c" , &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    int* min_pre = (int*)malloc(sizeof(int) * (n+1));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%*c" , &arr[i]);
        min_pre[i] = arr[i];
    }
    min_pre[n] = __INT_MAX__;
    int curr_min = min_pre[n-1];
    for(int i = n-1 ; i >= 0 ; i--)
    {
        min_pre[i] = curr_min = min(min_pre[i] , curr_min);
    }
    int ans = 0;
    int cur_max = 0;

    for (int i = 0; i < n; i++)
    {
        cur_max = max(cur_max , arr[i]);
        if(cur_max <= min_pre[i+1])
        {
            ans++;
            cur_max = 0;
        }
    }
    

    printf("%d" , ans);
    
    
}
