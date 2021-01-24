#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool** graph;
bool* visited;
int* coloring;
int n = 0;
const int ROOT_COLOR = 1;

const int invertColor(const int color){
    if(color == 1)return 2;
    return 1;
}

bool dfs(int node , const int color){
    bool ok = true;
    if(visited[node]) return (coloring[node] == color);
    visited[node] = true;
    coloring[node] = color;
    const int invertedColor = invertColor(color);
    for(int i = 0 ; i < n ; i++){
        if(graph[node][i]){
            ok = ok && dfs(i , invertedColor);
        }
    }
    return ok;
}

int main()
{
    int m;
    scanf("%d%d",&n,&m);
    graph = (bool**)malloc(sizeof(bool*) * n);
    visited = (bool*)malloc(sizeof(bool) * n);
    coloring = (int*)malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++){
        graph[i] = (bool*)malloc(sizeof(bool) * n);
        visited[i] = false;
        coloring[i] = 0;
        for(int j = 0 ; j < n ; j++)
            graph[i][j] = false;
    }
    int u,v;
    while(m--){
        scanf("%d%d" , &u , &v);
        graph[u][v] = 1;
        graph[v][u] = 1;       
    }
    for(int i = 0 ; i < n ; i++){
        if(visited[i] == false){
            if(dfs(i,ROOT_COLOR) == false)
            {
                printf("NEED MORE COLOURS\n");
                return 0;
            }
        }
    }
    for(int i = 0 ; i < n; i++)
        printf("%c" , coloring[i] == 1 ? 'R' : 'B');
    return 0;
}