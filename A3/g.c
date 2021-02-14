#include <stdio.h>
#include <stdlib.h>

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

int upper_bound(int* arr , int len , int k)
{
    int ans = len;
    int l = 0  , r = len - 1;
    int mid = l + (r-l)/2;
    while (l <= r)
    {
        mid = l + (r-l)/2;
        if(arr[mid] > k)
        {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    return ans;
}

int main()
{
    int m,n;
    scanf("%d %d%*c" , &m , &n);
    int* costs = (int*)malloc(sizeof(int) * m);
    int* budget = (int*)malloc(sizeof(int) * n);
    for (int  i = 0; i < m; i++)scanf("%d%*c" , &costs[i]);
    for (int  i = 0; i < n; i++)scanf("%d%*c" , &budget[i]);
    mergeSort(costs , 0 , m-1);
    for (int i = 0; i < n; i++)
    {
        int loc = upper_bound(costs , m , budget[i]);
        printf("%d " , loc);
    }
    
}