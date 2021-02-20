#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

#define article struct article
article{
    int id;
    float prob;
};

#define vertex struct vertex
vertex{
    int val;
    vertex* next;    
};

int n;
vertex* graph;
bool* visited;

float** probablity;
float* ans;

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

void dfs(int node , float reachProb)
{
    if(visited[node])
        return ;
    float sum;
    {
        visited[node] = true;
        sum = 0.0;
    }
    vertex* list = graph[node].next;
    while (list != NULL)
    {   
        sum += probablity[node][list->val];
        dfs(list -> val , reachProb * probablity[node][list -> val]);
        list = list -> next;
    }
    //post visit node
    {
        ans[node] = reachProb*(1 - sum);
    }
}


void merge(article* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    article* L = (article*)malloc(sizeof(article) * n1);
    article* R = (article*)malloc(sizeof(article) * n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].prob >= R[j].prob) {
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
void mergeSort(article* arr, int l, int r)
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
    int e , s;
    scanf("%d %d %d%*c" , &n , &e , &s);

    init(n); // initializing the graph

    probablity = (float**)malloc(sizeof(float*) * n);
    ans = (float*)malloc(sizeof(float) * n);
    rep(i,n){
        probablity[i] = (float*)malloc(sizeof(float) * n);
        ans[i] = 0.0;
    }
    while(e--)
    {
        int u , v;
        float prob;
        scanf("%d %d %f%*c" , &u , &v , &prob);
        //printf("%d %d %f\n" , u , v , prob);
        addEdge(u,v);
        probablity[u][v] = prob;
    }

    dfs(s , 1.0f);

    // rep(i,n)printf("%f " , ans[i]);
    // printf("\n");

    article* articles = (article*)malloc(sizeof(article ) * n);

    rep(i,n)
    {
        articles[i].id = i;
        articles[i].prob = ans[i];
    }

    mergeSort(articles , 0 , n-1);
    rep(i,n)printf("%d ", articles[i].id);

}