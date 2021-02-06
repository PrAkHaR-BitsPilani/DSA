#include <stdio.h>
#include <stdlib.h>

#define noble struct noble

noble{
    int bodyguard_skill;
    int gold;
};

void merge(noble* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    noble* L = (noble*)malloc(sizeof(noble) * n1);
    noble* R = (noble*)malloc(sizeof(noble) * n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].bodyguard_skill <= R[j].bodyguard_skill) {
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
void mergeSort(noble* arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int upper_bound(noble* nobles , int l , int r , int k)
{
    int ans = r+1;
    int mid = l + (r - l) /2;
    while(l <= r)
    {
        mid = l + (r - l) /2;
        if(nobles[mid].bodyguard_skill > k){
            r = mid- 1;
            ans = mid;
        }
        else l = mid+1;
    }
    return ans -1;
}

int main(){
    int n,m;
    scanf("%d %d%*c" , &n , &m);
    int* a_skill = (int*)malloc(sizeof(int) * n);
    noble* nobles = (noble*)malloc(sizeof(noble) * m);
    for (int i = 0; i < n; i++)scanf("%d" , &a_skill[i]);
    for (int i = 0; i < m; i++)scanf("%d %d%*c" , &nobles[i].bodyguard_skill , &nobles[i].gold);
    mergeSort(nobles , 0 , m-1);
    for(int i = 1 ; i < m ; i++)
        nobles[i].gold += nobles[i-1].gold;
    for (int i = 0; i < n; i++)
    {
        int loc = upper_bound(nobles , 0 , n-1 , a_skill[i]); // create this    
        if(loc == -1)
            printf("0 ");
        else printf("%d " , nobles[loc].gold);
    }
    
}