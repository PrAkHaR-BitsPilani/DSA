#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool search(int* notes , int len , int key)
{
    int l = 0;
    int r = len - 1;
    int mid = l + (r-l)/2;
    while(l <= r)
    {
        mid = l + (r-l)/2;
        if(notes[mid] == key)
            return true;
        if(notes[mid] > key)
            r = mid - 1;
        if(notes[mid] < key)
            l = mid+1;
    }
    return false;
}

int main()
{
    int n , q;
    scanf("%d %d%*c" , &n , &q);
    int* notes = (int*)malloc(sizeof(int) * n);
    rep(i,n)scanf("%d%*c" , &notes[i]);
    mergeSort(notes, 0 , n-1);
    while(q--)
    {
        int x;
        scanf("%d%*c" , &x);
        if(search(notes , n , x))printf("YES\n");
        else printf("NO\n");
    }
}