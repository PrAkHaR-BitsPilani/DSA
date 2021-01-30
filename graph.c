#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool** graph;
bool* visited;
int n = 0;

void dfs(int node){
    if(visited[node]) return ;
    visited[node] = true;
    for(int i = 0 ; i < n ; i++){
        if(graph[node][i]){
            dfs(i);
        }
    }
    return;
}

int main()
{
    int m;
    scanf("%d%d",&n,&m);
    graph = (bool**)malloc(sizeof(bool*) * n);
    visited = (bool*)malloc(sizeof(bool) * n);
    for(int i = 0 ; i < n ; i++){
        graph[i] = (bool*)malloc(sizeof(bool) * n);
        visited[i] = false;
        for(int j = 0 ; j < n ; j++)
            graph[i][j] = false;
    }
    int u,v;
    while(m--){
        scanf("%d%d" , &u , &v);
        u -= 1  , v -= 1;
        graph[u][v] = 1;
        graph[v][u] = 1; // comment this line if graph is directed       
    }
    return 0;
}