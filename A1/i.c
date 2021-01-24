#include<stdio.h>
#include<stdlib.h>

#define node struct node

node{
    int val;
    node* previous;
};

int main()
{
    int n;
    scanf("%d" , &n);
    node* list = (node*)malloc(sizeof(node));
    list->val = -1;
    list->previous = NULL;
    while(n != -1){
        node* temp = (node*)malloc(sizeof(node));
        temp -> val = n;
        temp -> previous = list;
        list = temp;
        scanf("%d" , &n);
    }
    while(list -> val != -1){
        printf("%d " , list -> val);
        list = list -> previous;
    }
    return 0;
}