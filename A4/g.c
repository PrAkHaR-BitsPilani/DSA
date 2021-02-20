#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

#define pad struct pad
pad{
    int loc;
    int freq;
};

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

int dfs(int node)
{
    if(visited[node])
        return 0;
    // pre visit node
    int ans;
    {
        visited[node] = true;
        ans = 1;
    }
    vertex* list = graph[node].next;
    while (list != NULL)
    {   
        ans += dfs(list -> val);
        list = list -> next;
    }
    //post visit node
    {

    }
    return ans;
}

void merge(pad* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    pad* L = (pad*)malloc(sizeof(pad) * n1);
    pad* R = (pad*)malloc(sizeof(pad) * n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] . freq <= R[j].freq) {
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
void mergeSort(pad* arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    scanf("%d%*c" , &n);
    pad* a = (pad*)malloc(sizeof(pad) * n);
    pad* b = (pad*)malloc(sizeof(pad) * n);

    rep(i,n)scanf("%d%*c" , &a[i].freq) , a[i].loc = i , b[i] = a[i];
    mergeSort(b , 0 , n-1);
    
    init(n);

    rep(i,n)
        if(b[i].loc != i)addEdge(b[i].loc , i);   

    int ans = 0;
    rep(i,n)
        if(!visited[i])ans += dfs(i);

    printf("%d" , ans);

}