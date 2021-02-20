#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

#define amp struct amp

#define cos45 0.52532198881
#define sin45 0.52532198881

amp{
    double x,y;
    int power;
};

void merge(amp* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    amp* L = (amp*)malloc(sizeof(amp) * n1);
    amp* R = (amp*)malloc(sizeof(amp) * n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].y <= R[j].y) {
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
void mergeSort(amp* arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

amp* amps;
int n = 0;

void transform()
{
    rep(i,n)
    {
        double x1 = amps[i].x * cos45 + amps[i].y * sin45;
        double y1 = -amps[i].x * sin45 + amps[i].y * cos45;
        amps[i].x = x1;
        amps[i].y = y1;
    }
}

bool check()
{
    mergeSort(amps , 0 , n-1);
    long long* prefix_sums = (long long*)malloc(sizeof(long long) * n);
    int j = 0;
    long long sum = 0LL;
    rep(i,n)
    {
        prefix_sums[j] = (long long)amps[i].power;
        if(j)prefix_sums[j] += prefix_sums[j-1];
        int k = i+1;
        while(k < n && amps[k].power == amps[i].power)
            prefix_sums[j] += (long long)amps[i].power , k++;
        i = k-1;
        j++;
    }

    rep(i,j-1)
    {
        if(sum == (prefix_sums[j-1] - prefix_sums[i]))
            return true;
        if(prefix_sums[i] == (prefix_sums[j-1] - prefix_sums[i]))
            return true;
        if(sum == (prefix_sums[j-1] - sum))
            return true;
        sum = prefix_sums[i];
    }
    
    return false;
}

int solve()
{
    scanf("%d%*c" , &n);
    amps = (amp*)malloc(sizeof(amp) * n);
    int powerSum = 0;
    rep(i,n)
    {
        int x,y,p;
        scanf("%d %d %d%*c" , &x , &y , &p);
        amps[i].x = x; 
        amps[i].y = y;
        amps[i].power = p;
        powerSum += p;
    }
    if(powerSum&1) return printf("NO");
    transform();
    if(check())printf("YES");
    else printf("NO");

}

int main()
{
    int t;
    scanf("%d%*c" , &t);
    while(t--)
        solve();
}