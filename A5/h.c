#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define priority_queue struct priority_queue

priority_queue{
    int n;
    int size;
    int* arr;
    bool (*compare) (int first , int second);
};

bool min(int first , int second){return first < second;}
bool max(int first , int second){return first > second;}

void swap(int* a , int* b){
    int valA = *a;
    int valB = *b;
    *a = valB;
    *b = valA;
}

int getParent(int node){return (node-1)/2;}
int getLeft(int node){return (2*node + 1);}
int getRight(int node){return (2*node+2);}

priority_queue* init( int len , bool (*comp) (int first , int second))
{
    priority_queue* queue = (priority_queue*)malloc(sizeof(priority_queue));
    queue -> n = len;
    queue -> arr = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)queue -> arr[i] = 0;
    queue -> compare = comp;
    queue -> size = 0;
    return queue;
}

void shiftUp(priority_queue* queue , int node)
{
    if(node == 0)return;
    int parent = getParent(node);
    if(queue -> compare(queue -> arr[node] , queue -> arr[parent]))
    {
        swap(queue -> arr+node , queue -> arr+parent);
        shiftUp(queue , parent);
    }
}

void shiftDown(priority_queue* queue , int node)
{
    int finalIndex = node;
    int left = getLeft(node);
    if(left < queue -> size && queue -> compare(queue -> arr[left] , queue -> arr[node]))
        finalIndex = left;
    int right = getRight(node);
    if(right < queue -> size && queue -> compare(queue -> arr[right] , queue -> arr[finalIndex]))    
        finalIndex = right;
    if(finalIndex != node){
        swap(queue -> arr+node , queue -> arr+finalIndex);
        shiftDown(queue , finalIndex);
    }
}

void insert(priority_queue* queue , int val)
{
    queue -> arr[queue -> size] = val;
    queue -> size++;
    shiftUp(queue , queue -> size-1);
}

int getTop(priority_queue* queue){ return queue -> arr[0];  }

int removeTop(priority_queue* queue)
{
    int res = getTop(queue);
    queue -> arr[0] = queue -> arr[queue -> size-1];
    queue -> size--;
    shiftDown(queue , 0);
    return res;
}


int main()
{
    int n;
    scanf("%d%*c" , &n);
    priority_queue* lower = init(n , max);
    priority_queue* higher = init(n , min);
    int median = 0;
    while(n--)
    {
        int temp;
        scanf("%d%*c" , &temp);
        if(lower->size == 0 || temp < median)
            insert(lower , temp);
        else insert(higher , temp);
        priority_queue* a = lower->size > higher->size ? lower : higher;
        priority_queue* b = lower->size > higher->size ? higher : lower;
        if(a->size - b->size >= 2)
            insert(b , removeTop(a));
        if(a->size == b->size)
            median = (getTop(a)+getTop(b))/2;
        else median = getTop(a);
        printf("%d " , median);

    }
}