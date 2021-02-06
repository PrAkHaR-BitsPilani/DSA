#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* A;
int* S;
int**memo;
int n,m,k;

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

int max(int a , int b)
{
    if(a > b)return a;
    return b;
}

bool compatible(int i , int j)
{
    int diff = A[i] - S[j];
    if(diff < 0)diff *= -1;
    return (diff <= k);
}

int dp(int i , int j)
{
    if(i == n || j == m)return 0;
    if(memo[i][j])
        return memo[i][j];
    int a =  -__INT_MAX__;
    int b = a , c = a;
    if(compatible(i,j))
       a = 1 + dp(i+1 , j+1);
    b = dp(i , j+1);
    c = dp(i+1 , j);
    return memo[i][j] = max(max(a,b),c);
}

int main()
{
    scanf("%d %d %d\n" , &n, &m , &k);
    A = (int*)malloc(sizeof(int) * n);
    S = (int*)malloc(sizeof(int) * m);
    memo = (int**)malloc(sizeof(int*) * n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d" , &A[i]);
        memo[i] = (int*)malloc(m * sizeof(int));
        for(int j = 0 ; j < m ; j++)memo[i][j] = 0;    
    }
    for(int i = 0 ; i < m ; i++)
        scanf("%d" , &S[i]);
    mergeSort(A , 0, n-1);
    mergeSort(S , 0, m-1);
    printf("%d" , dp(0,0));
}