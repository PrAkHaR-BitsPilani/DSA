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

void init(int n)
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

int* queue; // ** NOT A GENERIC QUEUE
int head = 0;
int size = 0;

int min(int a , int b)
{
    if(a < b)
        return a;
    return b;
}

void push(int x) // specialized for my graph
{
    queue[size++] = x;
    return;
}

int pop() // // specialized for my graph 
{
    if(head == size)return -1;
    return queue[head++];
}

void bfs(int node)
{
    queue = (int*)malloc(sizeof(int)*n);
    if(visited[node])
        return;
    push(node);
    int topNode = pop();
    visited[topNode] = true;
    while(topNode != -1)
    {
        vertex* temp = &graph[topNode];
        while(temp != NULL)
        {
            if(visited[temp->val] == false)
            {
                push(temp -> val);
                visited[temp -> val] = true;
            }
            temp = temp -> next;
        }
        topNode = pop();
    }
}

int main()
{
    int m , a , b;
    scanf("%d %d %d %d\n",&n,&m,&a,&b);
    init(n);
    int u,v;
    while(m--){
        scanf("%d %d\n" , &u , &v);
        addEdge(u,v);
        addEdge(v,u);
    }
    return 0;
}