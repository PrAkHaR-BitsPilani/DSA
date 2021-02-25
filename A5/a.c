#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define task struct task

task{
    int prioirity;
    int time;
    int index;
};

bool min(task first , task second){
    if(first.prioirity != second.prioirity)return first.prioirity < second.prioirity;
    if(first.time != second.time)return first.time < second.time;
    return true;
}

void swap(task* a , task* b){
    task valA = *a;
    task valB = *b;
    *a = valB;
    *b = valA;
}

int getParent(int node){return (node-1)/2;}
int getLeft(int node){return (2*node + 1);}
int getRight(int node){return (2*node+2);}

int n;
int size;
task* arr;
bool (*compare) (task first , task second);

void init(int len , bool (*comp) (task first , task second))
{
    n = len;
    arr = (task*)malloc(sizeof(task) * n);
    for (int i = 0; i < n; i++)arr[i].prioirity = arr[i].time = 0;
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

void insert(task val)
{
    arr[size] = val;
    size++;
    shiftUp(size-1);
}

task getTop(){ return arr[0]; }

task removeTop()
{
    task res = getTop();
    arr[0] = arr[size-1];
    size--;
    shiftDown(0);
    return res;
}

int main()
{
    int T , k;
    scanf("%d %d%*c" , &T , &k);
    init(T , min);
    int index = 0;
    while (T--)
    {
        int p , t;
        scanf("%d %d%*c" , &t , &p);
        task* temp = (task*)malloc(sizeof(task));
        temp -> prioirity = p;
        temp -> time = t;
        temp -> index = index;
        index++;
        insert(*temp);
    }

    while(k--)printf("%d " , removeTop().index);
    
}