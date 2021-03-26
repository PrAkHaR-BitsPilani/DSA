#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


#define machine struct machine

machine{
    int freetime;
    int optime;
};

int max(int a , int b)
{
    if(a > b)return a;
    return b;
}

machine* machines;

bool min(int first , int second){return machines[first].freetime < machines[second].freetime;}

void swap(int* a , int* b){
    int valA = *a;
    int valB = *b;
    *a = valB;
    *b = valA;
}

int getParent(int node){return (node-1)/2;}
int getLeft(int node){return (2*node + 1);}
int getRight(int node){return (2*node+2);}

int n;
int size;
int* arr;
bool (*compare) (int first , int second);

void init(int len , bool (*comp) (int first , int second))
{
    n = len;
    arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)arr[i] = 0;
    compare = comp;
    size = 0;
}

void shiftUp(int node)
{
    if(node == 0)return;
    int parent = getParent(node);
    if(compare(arr[node] , arr[parent]))
    {
        swap(arr+node , arr+parent);
        shiftUp(parent);
    }
}

void shiftDown(int node)
{
    int finalIndex = node;
    int left = getLeft(node);
    if(left < size && compare(arr[left] , arr[node]))
        finalIndex = left;
    int right = getRight(node);
    if(right < size && compare(arr[right] , arr[finalIndex]))    
        finalIndex = right;
    if(finalIndex != node){
        swap(arr+node , arr+finalIndex);
        shiftDown(finalIndex);
    }
}

void insert(int val)
{
    arr[size] = val;
    size++;
    shiftUp(size-1);
}

int getTop(){ return arr[0]; }

int removeTop()
{
    int res = getTop();
    arr[0] = arr[size-1];
    size--;
    shiftDown(0);
    return res;
}


int main()
{
    int melons;
    scanf("%d %d%*c" , &n , &melons);
    machines = (machine*)malloc(sizeof(machine) * n);
    init(n , min);
    for (int i = 0; i < n; i++)
    {
        int optime;
        scanf("%d%*c" , &optime);
        machines[i].freetime = machines[i].optime = optime;
        insert(i);
    }
    while(melons)
    {
        int index = removeTop();
        machines[index].freetime += machines[index].optime;
        insert(index);
        melons--;
    }
    int total_time = 0;
    for (int i = 0; i < n; i++)
    {
        total_time = max(total_time , machines[i].freetime - machines[i].optime);
    }
    
    printf("%d" , total_time);
    
}