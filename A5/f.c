#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define vertex struct vertex

vertex{
    int val;
    vertex* next;    
};

int n;
vertex* graph;
bool* visited;

void init_graph(int n)
{
    graph = (vertex*)malloc(sizeof(vertex) * n);
    visited = (bool*)malloc(sizeof(bool) * n);
    for(int i = 0 ; i < n ; i++)
    {
        visited[i] = false;
        graph[i].val = i;
        graph[i].next = NULL;
    }
}
void addEdge(int u , int v)
{
    vertex* temp = (vertex*)malloc(sizeof(vertex));
    temp -> val = v;
    temp -> next = NULL;
    if(graph[u].next == NULL)
        graph[u].next = temp;
    else{
        vertex* temp1 = graph[u].next;
        temp -> next = temp1;
        graph[u].next = temp;

    }
}
void dfs(int node)
{
    if(visited[node])
        return ;
    // pre visit node
    {
        visited[node] = true;
    }
    vertex* list = graph[node].next;
    while (list != NULL)
    {   
        dfs(list -> val);
        list = list -> next;
    }
    //post visit node
    {

    }
}

// PRIORITY QUEUE
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

void bfs(int node)
{
    init_priorityQueue(n , min);
    if(visited[node])
        return;
    insert(node);
    int topNode = getTop();
    visited[topNode] = true;
    while(size)
    {
        removeTop();

        printf("%d " , topNode+1);

        vertex* temp = &graph[topNode];
        while(temp != NULL)
        {
            if(visited[temp->val] == false)
            {
                insert(temp -> val);
                visited[temp -> val] = true;
            }
            temp = temp -> next;
        }
        if(size)
            topNode = getTop();
        else break;
    }
}

int main()
{
    int m;
    scanf("%d %d%*c",&n,&m);
    init_graph(n);
    int u,v;
    while(m--){
        scanf("%d %d\n" , &u , &v);
        u-- , v--;
        addEdge(u,v);
        addEdge(v,u);
    }
    bfs(0);
    return 0;
}