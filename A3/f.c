#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool** graph;
bool* visited;
int n = 0;

void merge(int* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = (int*)malloc(sizeof(int) * n1);
    int* R = (int*)malloc(sizeof(int) * n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int* arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

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
    mergeSort(ans,0,n-1);
    int sum = 0;
    for(int i = n-1 ; i >= 0 ; i--)
    {
        sum += ans[i];
        if((sum*10) > (8*n))
        {
            printf("%d" , n-i);
            break;
        }
    }
    return 0;
}