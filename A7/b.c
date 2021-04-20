#include <stdlib.h>
#include <stdio.h>

int* arr;
int size;
int top = 0;

void init(int n)
{
    arr = (int*)malloc(sizeof(int) * n);
    size = n;
    top = 0;
}

int push(int e)
{
    if(top == size)
        return 0;
    arr[top++] = e;
    return 1;
}

int getTop()
{
    if(top == 0)return -1;
    return arr[top - 1];
}

int pop()
{
    if(top == 0)return -1;
    return arr[--top];
}

int isEmpty()
{
    return top == 0;
}

int main()
{
    int n;
    scanf("%d%*c" , &n);
    init(n);
    int* a = (int*)malloc(sizeof(int) * n);
    int* left = (int*)malloc(sizeof(int) * n);
    int* right = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%*c" , &a[i]);
        int e = getTop();
        while(!isEmpty() && a[e] >= a[i])
        {
            pop();
            e = getTop();
        }

        if(isEmpty())left[i] = -1;
        else left[i] = e;
        push(i);
    }
    init(n);
    for (int i = n-1; i >= 0; i--)
    {
        int e = getTop();
        while(!isEmpty() && a[e] >= a[i])
        {
            pop();
            e = getTop();
        }

        if(isEmpty())right[i] = n;
        else right[i] = e;
        push(i);
    }
    int ans = a[0] * right[0];
    for(int i = 0; i < n ; i++)
    {
        int temp =a[i] * (right[i] - i + i - left[i] - 1);
        //printf("%d\n" , temp);
        if(temp > ans)ans = temp;
    }
    printf("%d " , ans);
    return 0;
}

    