#include <stdio.h>
#include <stdlib.h>

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

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

int last_occurence(int* arr , int x , int len){
    int l = 0;
    int r = len - 1;
    int mid = l + (r-l)/2;
    int ans = len;
    while(l <= r)
    {
        mid = l + (r-l)/2;
        if(arr[mid] < x)
            l = mid+1;
        if(arr[mid] == x)
            ans = mid , l = mid+1;
        if(arr[mid] > x)
            r = mid - 1;
    }
    return ans;
}

int first_occurence(int* arr , int x , int len){
    int l = 0;
    int r = len - 1;
    int mid = l + (r-l)/2;
    int ans = 0;
    while (l <= r)
    {
        mid = l + (r-l)/2;
        if(arr[mid] < x)
            l = mid+1;
        if(arr[mid] == x)
            ans = mid , r = mid - 1;
        if(arr[mid] > x)
            r = mid - 1;
    }
    return ans;
    
}

int main()
{
    int m;
    scanf("%d%*c" , &m);
    int* arr = (int*)malloc(sizeof(int) * m);
    rep(i,m)scanf("%d%*c" , &arr[i]);
    mergeSort(arr, 0 , m-1);
    int diff = arr[m-1] - arr[0];
    int count = (1 + last_occurence(arr , arr[0] , m)) * (m - first_occurence(arr , arr[m-1] , m));
    printf("%d %d" , diff , count);
}