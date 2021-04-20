#include <stdio.h>
#include <stdlib.h>

#define node struct node

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define REP(i,k,n) for(int i = k ; i < n ; i++)

node{
    int val;
    node* left;
    node* right;
};

node* nodes;
int n;

int* inorder;
int* postorder;
int* preorder;

int arr_index;

void inorderTrav(node* root)
{
    if(root->left != NULL)inorderTrav(root->left);
    inorder[arr_index++] = root->val;
    if(root->right != NULL)inorderTrav(root->right);
}

void preorderTrav(node* root)
{
    preorder[arr_index++] = root->val;
    if(root->left != NULL)preorderTrav(root->left);
    if(root->right != NULL)preorderTrav(root->right);
}

void postorderTrav(node* root)
{
    if(root->left != NULL)postorderTrav(root->left);
    if(root->right != NULL)postorderTrav(root->right);
    postorder[arr_index++] = root->val;
}


int main()
{
    scanf("%d" , &n);
    nodes = (node*)malloc(sizeof(node) * n);
    inorder = (int*)malloc(sizeof(int) * n);
    preorder = (int*)malloc(sizeof(int) * n);
    postorder = (int*)malloc(sizeof(int) * n);
    rep(i,n)scanf(" %d" , &nodes[i].val),nodes[i].left = nodes[i].right = NULL;
    rep(i,n-1)
    {
        int x,y;
        char c;
        scanf(" %d %d %c" , &x , &y , &c);
        if(c == 'L')
            nodes[x].left = nodes + y;
        else
            nodes[x].right = nodes + y;
    }

    arr_index = 0;
    inorderTrav(nodes);
    arr_index = 0;
    preorderTrav(nodes);
    arr_index = 0;
    postorderTrav(nodes);

    rep(i,n)printf("%d " , preorder[i]);
    printf("\n");
    rep(i,n)printf("%d " , postorder[i]);
    printf("\n");
    rep(i,n)printf("%d " , inorder[i]);

    
}