#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool** graph;
int** weight;
bool* visited;
int* dist;
int n = 0;

void init()
{
    graph = (bool**)malloc(sizeof(bool*) * n);
    weight = (int**)malloc(sizeof(int*) * n);
    visited = (bool*)malloc(sizeof(bool) * n);
    dist = (int*)malloc(sizeof(int) * n);

    for(int i = 0 ; i < n ; i++){
        graph[i] = (bool*)malloc(sizeof(bool) * n);
        weight[i] = (int*)malloc(sizeof(int) * n);
        dist[i] = __INT_MAX__;
        visited[i] = false;
        for(int j = 0 ; j < n ; j++){
            graph[i][j] = false;
            weight[i][j] = __INT_MAX__;
        }
    }
}
void addEdge(int u , int v , int edge_weight)
{
    graph[u][v] = 1;
    weight[u][v] = edge_weight;
}

bool min(int first , int second){return dist[first] < dist[second];}
void swap(int* a , int* b){
    int valA = *a;
    int valB = *b;
    *a = valB;
    *b = valA;
}
int getParent(int node){return (node-1)/2;}
int getLeft(int node){return (2*node + 1);}
int getRight(int node){return (2*node+2);}
int size;
int* arr;
bool (*compare) (int first , int second);
void init_priorityQueue(int len , bool (*comp) (int first , int second))
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

void bfs(int node){
    init_priorityQueue(n , min);
    dist[node] = 0;
    insert(node);
    int topNode = getTop();
    while(size)
    {
        removeTop();

        for(int i = 0 ; i < n ; i++)
        {
            if(graph[topNode][i])
            {
                if((dist[i] == __INT_MAX__) || ((dist[topNode]+weight[topNode][i]) < dist[i]))
                {
                    dist[i] = dist[topNode] + weight[topNode][i];
                    insert(i);
                }
            }
        }
        if(size)topNode = getTop();
    }
}

int main()
{
    int m , source;
    scanf("%d %d %d%*c",&n,&m,&source);
    init();
    int u,v,w;
    while(m--){
        scanf("%d %d %d%*c" , &u , &v , &w);
        addEdge(u,v,w);
        addEdge(v,u,w);
    }

    bfs(source);

    for (int i = 0; i < n; i++)
    {
        printf("%d " , dist[i]);
    }
    
    return 0;
}