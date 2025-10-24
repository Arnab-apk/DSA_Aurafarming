#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

//prototypes
struct node* createnode(int);
void insertAtBeginning(struct node** ,int);
void insertAtEnd(struct node** ,int);
void deleteNode(struct node** ,int);
void displayList(struct node*);
void freeList(struct node**);

struct node* createnode(int data){
    struct node* newnode=(struct Node*)malloc(sizeof(struct node));
    if (newnode==NULL){
        printf("memory allocation failed!\n");
        exit(1);
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}





