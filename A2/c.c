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
    int* deg = (int*)malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++){
        graph[i] = (bool*)malloc(sizeof(bool) * n);
        visited[i] = false;
        deg[i] = 0;
        for(int j = 0 ; j < n ; j++)
            graph[i][j] = false;
    }
    int u,v;
    while(m--){
        scanf("%d%d" , &u , &v);
        u -= 1  , v -= 1;
        graph[v][u] = 1;
        deg[v]++;
        deg[u]++;
    }
    int x = -1 , y;
    for(int i = 0 ; i < n ; i++){
        if(deg[i] != (n-1))
            if(x == -1)x = i;
            else y = i;
    }
    dfs(x);
    bool ans1 = visited[y];
    for(int i = 0 ; i < n ; i++)visited[i] = false;
    dfs(y);
    bool ans2 = visited[x];
    if((ans1 ^ ans2) && ans1)
        printf("%d %d" , x+1 , y+1);
    else  printf("%d %d" , y+1 , x+1);
    return 0;
}