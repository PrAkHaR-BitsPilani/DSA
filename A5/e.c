#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

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

int main(){
    int n ,k;
    scanf("%d %d%*c" , &n , &k);
    init(n , max);
    int prev;
    scanf("%d%*c" , &prev);
    rep(i,n-1)
    {
        int temp;
        scanf("%d%*c", &temp);
        insert(temp - prev);
        prev = temp;
    }
    rep(i,k){
        int t = removeTop();
        insert(t/2);
        insert(t-t/2);
    }
    printf("%d" , getTop());

}