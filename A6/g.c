#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int asize = 0 , bsize =  0;
int* tree;
int* leafA;
int* leafB;
int size;

bool isLeaf(int index)
{
    bool right = ((2*index + 1) >= size) || (tree[2*index+1] == -1);
    bool left = ((2*index + 2) >= size) || (tree[2*index+2] == -1);
    return right & left;
}

int hummDist(int a , int b)
{
    int count = 0;
    int val = a^b;
    while(val)
    {
        count += val & 1;
        val >>= 1;
    }
    return count;
}

void fill(int index , int mode)
{
    if(index >= size)return;
    if(tree[index] == -1)return;
    if(mode == 1)
    {
        if(isLeaf(index))
        {
            leafA[asize++] = tree[index];
            return;
        }
        fill(2*index+1 , mode);
        fill(2*index+2 , mode);
    }
    else
    {
        if(isLeaf(index))
        {
            leafB[bsize++] = tree[index];
            return;
        }
        fill(2*index+1 , mode);
        fill(2*index+2 , mode);
    }
}

int main()
{
    int N , a , b;
    scanf("%d %d %d%*c" , &N , &a , &b);
    size = N;
    tree = (int*)malloc(sizeof(int) * N);
    int aloc = -1 , bloc = -1;
    for (int i = 0; i < N; i++)
    {
        scanf("%d%*c" , &tree[i]);
        if(tree[i] == a)aloc = i;
        if(tree[i] == b)bloc = i;
    }
    if(aloc == -1 || bloc == -1)
    {
        printf("%d" , -1);
        return 0;
    }
    leafA = (int*)malloc(sizeof(int) * N);
    leafB = (int*)malloc(sizeof(int) * N);
    fill(aloc , 1);
    fill(bloc , 2);

    int ans = __INT_MAX__;
    // brute force
    for (int i = 0; i < asize; i++)
    {
        for (int j = 0; j < bsize; j++)
        {
            if(ans > hummDist(leafA[i] , leafB[j]))
                ans = hummDist(leafA[i] , leafB[j]);
        }
        
    }
    
    printf("%d" , ans);

}