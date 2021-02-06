#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define vertex struct vertex

int min(int a , int b)
{
    if(a < b)
        return a;
    return b;
}

vertex{
    int val;
    vertex* next;    
};

vertex* graph;
bool* visited;
int* dist;
int n = 0;

int* queue; // ** NOT A GENERIC QUEUE
int head = 0;
int size = 0;

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
    if(visited[node])
        return;
    push(node);
    int topNode = pop();
    visited[topNode] = true;
    dist[topNode] = 0;
    while(topNode != -1)
    {
        vertex* temp = &graph[topNode];
        while(temp != NULL)
        {
            if(visited[temp->val] == false)
            {
                dist[temp -> val] = min(dist[temp->val] , dist[topNode]+ 1);
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
    graph = (vertex*)malloc(sizeof(vertex) * n);
    visited = (bool*)malloc(sizeof(bool) * n);
    dist = (int*)malloc(sizeof(int) * n);
    queue = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dist[i] = __INT_MAX__;
        graph[i].val = i;
        graph[i].next = NULL;
    }
    int u,v;
    while(m--){
        scanf("%d %d\n" , &u , &v);
        vertex* temp = (vertex*)malloc(sizeof(vertex) * n);
        temp -> val = v;
        temp -> next = NULL;
        if(graph[u].next == NULL)
            graph[u].next = temp;
        else
        {
            vertex* temp1 = graph[u].next;
            graph[u].next = temp;
            temp -> next = temp1;
        }
        temp = (vertex*)malloc(sizeof(vertex) * n);
        temp -> val = u;
        temp -> next = NULL;
        if(graph[v].next == NULL)
            graph[v].next = temp;
        else
        {
            vertex* temp1 = graph[v].next;
            graph[v].next = temp;
            temp -> next = temp1;
        }
    }
    return 0;
}