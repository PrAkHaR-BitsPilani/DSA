#include <stdio.h>
#include<stdlib.h>

#define node struct node

node{
    int val;
    int index;
};

void merge(node* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    node* L = (node*)malloc(sizeof(node) * n1);
    node* R = (node*)malloc(sizeof(node) * n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
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
void mergeSort(node* arr, int l, int r)
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
    int n;
    scanf("%d" , &n);
    node* arr = (node*)malloc(sizeof(node) * n);
    for(int i = 0 ; i < n; i++)
        scanf(" %d" , &arr[i].val),arr[i].index = i;
    for(int i = 1; i < n; i++)arr[i].val += arr[i-1].val;
    mergeSort(arr , 0 , n-1);
    for(int i = 0; i < n; i++)
    {
        printf("%d %d\n" , arr[i].val , arr[i].index);
    }

}