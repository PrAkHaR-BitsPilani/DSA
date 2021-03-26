#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , t;
    scanf("%d%*c%d%*c" , &n , &t);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%*c" , &arr[i]);
    }
    int rot = 0;
    while (t--)
    {
        int step;
        scanf("%d%*c" , &step);
        rot += step;
        rot %= n;
        printf("%d " , arr[rot]);
        if(rot)printf("%d " , arr[rot -1]);else printf("%d " , arr[n-1]);
        printf("\n");

    }
    
    
}