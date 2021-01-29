#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool** graph;
bool* visited;
int n = 0;

int dfs(int node){
    if(visited[node])return 0;
    visited[node] = true;
    int count = 1;
    for(int i = 0 ; i < n ; i++){
        if(graph[node][i]){
            count += dfs(i);
        }
    }
    return count;
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
        graph[u][v] = 1;
        graph[v][u] = 1;       
    }
    int key = 0;
    int* ans = (int*)malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++){
        ans[i] = 0;
        if(visited[i] == false){
            ans[key] = dfs(i);
            key++;
        }
    }
    printf("%d\n" , key);
    for(int i = 0 ; i < n; i++)
        if(ans[i])printf("%d " , ans[i]);
    return 0;
}