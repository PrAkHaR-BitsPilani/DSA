#include <stdlib.h>

#define node struct node

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