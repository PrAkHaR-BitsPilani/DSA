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
    for (int i = 0; i < n; i++)
    {
        scanf("%d%*c" , &a[i]);
        int e = getTop();
        while(!isEmpty() && a[e] >= a[i])
        {
            pop();
            e = getTop();
        }

        if(isEmpty())printf("%d " , -1);
        else printf("%d " , e+1);
        push(i);
    }
    
    return 0;
}

    