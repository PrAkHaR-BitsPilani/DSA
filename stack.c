#include <stdlib.h>

int* arr;
int size;
int top = 0;

void init(int n)
{
    arr = (int*)malloc(sizeof(int) * n);
    size = n;
    top = 0;
}

void push(int e)
{
    if(top == size)
        return 0;
    arr[top++] = e;
    return 1;
}

int pop()
{
    if(top == 0)return -1;
    return arr[--top];
}

    