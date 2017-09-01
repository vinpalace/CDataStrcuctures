#include<stdio.h>
#include<stdlib.h>



struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

NODE *recent , temp = 0;

createnode()
{
    recent = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the data you want\n");
    scanf("%d",&recent->data);
    recent->left = NULL;
    recent->right = NULL;

    if(temp==0)
    {
        temp = recent;
    }
    else
    {
        if(recent->data < temp->data)
        {
            temp->left = recent;
        }
    }

}
