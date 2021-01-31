#include<stdio.h>
#include<stdlib.h>

#define node struct node

node{
    int val;
    node* next;
};

int main()
{
    int n;
    scanf("%d" , &n);
    node* root = (node*)malloc(sizeof(node));
    root -> val = -1;
    node* previous = root;
    while(n != -1){
        node* temp = (node*)malloc(sizeof(node));
        temp -> val = n;
        previous -> next = temp;
        previous = temp;
        scanf("%d" , &n);
    }
    previous -> next = NULL;
    previous = NULL;
    while(1){
        node* temp = root -> next;
        root -> next = previous;
        previous = root;
        root = temp;
        if(root == NULL)
            break;
    }
    while(previous -> val != -1){
        printf("%d " , previous -> val);
        previous = previous -> next;
    }
    return 0;
}