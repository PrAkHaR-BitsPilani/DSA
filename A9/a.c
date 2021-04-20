#include <stdio.h>
#include <stdlib.h>

int max(int a , int b)
{
    if(a > b)return a;
    return b;
}

#define node struct node

node{
    int val;
    int power2;
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
        if (L[i].val < R[j].val) {
            arr[k] = L[i];
            i++;
        }
        else if(L[i].val > R[j].val) {
            arr[k] = R[j];
            j++;
        }else{
            if(L[i].power2 > R[j].power2)
            {
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
            }
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
    scanf("%d%*c" , &n);
    node* nodes = (node*)malloc(sizeof(node) * n);
    for (int i = 0; i < n; i++)
    {
        int ele;
        scanf("%d%*c", &ele);
        int cnt = 0;
        while(ele%2 == 0)ele /= 2 , cnt++;
        nodes[i].val = ele;
        nodes[i].power2 = cnt;
    }
    mergeSort(nodes , 0 , n-1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int add = nodes[i].power2;
        while(i+1 < n && nodes[i].val == nodes[i+1].val)
            i++ , add = max(add , nodes[i].power2);
        ans += add;
    }
    
    printf("%d" , ans);
    
}