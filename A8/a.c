#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define node struct node

node{
    int val;
    node* left;
    node* right;
};

node* tree;
int n;
bool left = false;

void print(node* layer , int length)
{
    if(left)
    {
        for(int i = length-1; i >= 0; i--)
            printf("%d " , layer[i].val);
    }
    else{
        for(int i = 0; i < length; i++)
            printf("%d " , layer[i].val);
    }
    node* next;
    int newLength = 0;
    for(int i = 0; i < length; i++)
    {
        if(layer[i].left != NULL)newLength++;
        if(layer[i].right != NULL)newLength++;
    }
    next = (node*)malloc(sizeof(node) * newLength);
    int c = 0;
    for(int i = 0; i < length; i++)
    {
        if(layer[i].left != NULL)next[c++] = *(layer[i].left);
        if(layer[i].right != NULL)next[c++] = *(layer[i].right);
    }
    if(newLength)
    {
        left = !left;
        print(next , newLength);
    }
    return;

}

int main()
{
    scanf("%d%*c" , &n);
    tree = (node*)malloc(sizeof(node) * n);
    for(int i = 0; i < n; i++)
    {
        int val;
        scanf("%d%*c" , &val);
        tree[i].val = val;
        tree[i].left = NULL;
        tree[i].right = NULL;
    }
    for(int i = 0; i < n-1; i++)
    {
        int a , b;
        char c;
        scanf("%d %d %c%*c" , &a , &b , &c);
        if(c == 'L'){
            tree[a].left = &(tree[b]);
        }
        else{
            tree[a].right = &(tree[b]);
        }
    }
    node* layer = &tree[0];
    print(layer , 1);
}