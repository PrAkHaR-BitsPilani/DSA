#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

const int N = 26;

bool** graph;
bool* visited;
bool* subset;
int* parent;
char ans[30];
int curIndex = 0;
bool cyclic = false;

int getParent(int node)
{
    if(parent[node] == node)
        return node;
    parent[node] = getParent(parent[node]);
    return parent[node];
}

void dfs(int node)
{
    if(visited[node])
    {
        cyclic = true;
        return;
    }
    visited[node] = true;
    ans[curIndex] = 'A' + node;
    curIndex++;
    curIndex %= N;
    rep(i,N)
    {
        if(graph[node][i])
            dfs(i);
    }
}

int main()
{
    graph = (bool**)malloc(sizeof(bool*) * N);
    visited = (bool*)malloc(sizeof(bool) * N);
    subset = (bool*)malloc(sizeof(bool) * N);
    parent = (int*)malloc(sizeof(int) * N);
    bool* isRoot = (bool*)malloc(sizeof(bool) * N);
    rep(i,N)graph[i] = (bool*)malloc(sizeof(bool) * N) , visited[i] = subset[i] = isRoot[i] = false , parent[i] = i;
    rep(i,N)rep(j,N)graph[i][j] = false;
    int n;
    scanf("%d%*c" , &n);
    while(n--)
    {
        char u,v;
        scanf("%c%*c%c%*c" , &u , &v);
        graph[u-'A'][v-'A'] = true;
        subset[u-'A'] = subset[v-'A'] = true;
        parent[v-'A'] = u-'A';
    }
    rep(i,N)if(subset[i] && !visited[i])isRoot[getParent(i)] = true;
    rep(i,N)if(isRoot[i])dfs(i);
    if(cyclic)printf("ALIENS BE CRAZY");
    else printf("%s" , ans);

}