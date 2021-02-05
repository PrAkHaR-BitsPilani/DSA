#include<stdio.h>
#include<stdlib.h>

void sort(int* a , int l , int r) // bubble sort
{
    for(int i = l ; i <= r ; i++)
    {
        for(int j = l ; j < r ; j++)
            if(a[j] > a[j+1])
            {
                a[j] += a[j+1];
                a[j+1] = a[j] - a[j+1];
                a[j] -= a[j+1];
            }
    }
}

int main()
{
    int n;
    scanf("%d" , &n);
    int* s = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)scanf("%d" , &s[i]);
    int b;
    scanf("%d" , &b);
    sort(s , 0 , n-1);
    int l = 0;
    int r = n-1;
    int cnt = 0;
    while(l <= r)
    {
        if((s[l] + s[r]) <= b){
            l++;
            r--;
            cnt++;
        }else{
            r--;
            cnt++;
        }
    }
    printf("%d" , cnt);
}