#include  <stdio.h>
#include <stdlib.h>

#define point struct point

point{
    int x;
    int y;
    int index;
    int score;
};

void merge(point* arr, int l, int m, int r)
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
        if ((L[i].score < R[j].score) || (L[i].score == R[j].score && L[i].index < R[j].index)) {
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
void mergeSort(point* arr, int l, int r)
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

int main()
{
    int N , C , D , k;
    scanf("%d %d %d %d%*c" , &N , &C , &D , &k);
    int* B_x = (int*)malloc(sizeof(int) * C);
    int* B_y = (int*)malloc(sizeof(int) * D);
    for (int i = 0; i < max(C , D); i++)
    {
        B_x[i%C] = 0;
        B_y[i%D] = 0;
    }
    
    point* points = (point*)malloc(sizeof(point) * N);
    for (int i = 0; i < N; i++)
    {
        float x , y;
        scanf("%f %f%*c" , &x , &y);
        points[i].x = (int)x;
        points[i].y = (int)y;
        points[i].index = i;
        B_x[points[i].x]++;
        B_y[points[i].y]++;
    }
    for (int i = 0; i < N; i++)
    {
        points[i].score = B_x[points[i].x] * B_y[points[i].y];
    }
    mergeSort(points , 0 , N-1);
    for (int i = 0; i < k; i++)
    {
        printf("%d " , points[i].index);
    }
    
    
}