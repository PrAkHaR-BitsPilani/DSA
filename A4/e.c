#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

#define point struct point

point{
    int x;
    int y;
};

bool ascending(point A , point B)
{
    return (A.y * B.x) < (A.x * B.y);
}

bool descending(point A , point B)
{
    return (A.y * B.x) > (A.x * B.y);
}

void merge(point* arr, int l, int m, int r , bool (*comp)(point A , point B))
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    point* L = (point*)malloc(sizeof(point) * n1);
    point* R = (point*)malloc(sizeof(point) * n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if ((*comp)(L[i] , R[j])) {
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
void mergeSort(point* arr, int l, int r , bool (*comp)(point A, point B))
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m , comp);
        mergeSort(arr, m + 1, r , comp);

        merge(arr, l, m, r , comp);
    }
}

int absVal(int a)
{
    if(a < 0)return -a;
    return a;
}

int manhat(point A , point B)
{
    return absVal(A.x - B.x) + abs(A.y - B.y);
}

long long calc(point* points , int len)
{
    long long sum = 0LL;
    rep(i,len-1)
    {
        sum += (long long)manhat(points[i] , points[i+1]);
    }
    return sum;
}

int boringTask(point* Q1 , point* Q2 , point* Q3 , point* Q4 , int q1 , int q2 , int q3 , int q4)
{
    int ans = 0;
    if(q1 >= 1)
        if(q2 >= 1)
            ans = manhat(Q1[q1-1] , Q2[0]);
        else
            if(q3 >= 1)
                ans = manhat(Q1[q1-1] , Q3[0]);
            else
                if(q4 >= 1)
                    ans = manhat(Q1[q1-1] , Q4[0]);
                else
                    ans = manhat(Q1[q1-1] , Q1[0]);
    return ans;
}

int main(){
    int m;
    scanf("%d%*c",&m);
    point* points = (point*)malloc(sizeof(point) * m); 
    int q1 = 0 , q2 = 0 , q3 = 0 , q4 = 0;
    rep(i,m)
    {
        int x,y;
        scanf("%d %d%*c" , &x , &y);
        points[i].x = x;
        points[i].y = y;
        q1 += x>=0 && y>0;
        q2 += x<0 && y>=0;
        q3 += x<=0 && y<0;
        q4 += x>0 && y<=0;
    }
    point* Q1 = (point*)malloc(sizeof(point) * q1);
    point* Q2 = (point*)malloc(sizeof(point) * q2);
    point* Q3 = (point*)malloc(sizeof(point) * q3);
    point* Q4 = (point*)malloc(sizeof(point) * q4);
    q1 = q2 = q3 = q4 = 0;
    rep(i,m)
    {
        int x = points[i].x;
        int y = points[i].y;
        if(x>=0 && y>0)Q1[q1++] = points[i];
        if(x<0 && y>=0)Q2[q2++] = points[i];
        if(x<=0 && y<0)Q3[q3++] = points[i];
        if(x>0 && y <=0)Q4[q4++] = points[i];
    }
    mergeSort(Q1 , 0 , q1 - 1 , ascending);
    mergeSort(Q2 , 0 , q2 - 1 , ascending);
    mergeSort(Q3 , 0 , q3 - 1 , ascending);
    mergeSort(Q4 , 0 , q4 - 1 , ascending);

    long long ans = calc(Q1 , q1) + calc(Q2 , q2) + calc(Q3 , q3) + calc(Q4 , q4);

    ans += (long long)boringTask(Q1 , Q2 , Q3 , Q4 , q1 , q2 , q3 , q4);
    ans += (long long)boringTask(Q2 , Q3 , Q4 , Q1 , q2 , q3 , q4 , q1);
    ans += (long long)boringTask(Q3 , Q4 , Q1 , Q2 , q3 , q4 , q1 , q2);
    ans += (long long)boringTask(Q4 , Q1 , Q2 , Q3 , q4 , q1 , q2 , q3);

    printf("%lld" , ans);
    
    return 0;
}