#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <assert.h>

#define int long long

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
    int l= 0;
    int r = len - 1;
    int mid = l + (r -l)/2;
    while (l <= r)
    {
        mid = l + (r -l)/2;
        if(arr[mid] >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
}

int main(){
    int n,m,l;
    scanf("%lld %lld %lld%*c" , &n , &m , &l);
    int u,v,a,b,k;
    scanf("%lld %lld %lld %lld %lld%*c" , &u , &v , &a , &b , &k);
    //assert(u <= v);
    int* cities = (int*)malloc(sizeof(int) * m);
    for(int i = 0 ; i < m ; i++)scanf("%lld%*c" , &cities[i]);
    int* gas = (int*)malloc(sizeof(int) * l);
    int* dist = (int*)malloc(sizeof(int) * l);
    for(int i = 0 ; i < l ; i++)scanf("%lld%*c" , &gas[i]) , dist[i] = a*gas[i] + b;
    mergeSort(cities , 0 , m-1);
    mergeSort(gas , 0 , l-1);
    mergeSort(dist , 0 , l - 1);
    bool ok = false;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if(cities[i] < u)continue;
        if(cities[i] == v){
            ok = true;
            break;
        };
        int loc = upper_bound(dist , l , cities[i+1] - cities[i]);
        if(loc == l){
            ok = false;
            break;
        }else ans += k * gas[loc];
        
    }
    
    if(ok)printf("%lld" , ans);
    else printf("NOT POSSIBLE");
}