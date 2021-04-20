#include <stdio.h>
#include <stdlib.h>

int n,m;
int** map;
int** dist;

int main()
{
    scanf("%d %d%*c",&n,&m);
    map = (int**)malloc(sizeof(int*)*n);
    dist = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
    {
        map[i] = (int*)malloc(sizeof(int)*m);
        dist[i] = (int*)malloc(sizeof(int)*m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d%*c",&map[i][j]);
            dist[i][j] = 1e7*(1-map[i][j]);
        }
        
    }

    //use multisource BFS
    //uses simple queue DS
    return 0;
}