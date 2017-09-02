#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node NODE;


NODE* root = NULL;


NODE* Insert(NODE* root,int data);
int Search(NODE* root,int data);
void PostOrder(NODE* root);

void main()
{
    int choice = 1 , number;
    int searchdata;
    int value;

    while(choice)
    {
        printf("\nEnter the number you want to insert\n");
        scanf("%d",&number);

        root = Insert(root,number);

        printf("\nDo you want to continue ?\n");
        scanf("%d",&choice);
    }

    printf("\nEnter the number you want to search\n");
    scanf("%d",&searchdata);

    value = Search(root,searchdata);

    if(value == 1)
        printf("\nThe value is found\n");
    else
        printf("\nThe value is not found\n");

    PostOrder(root);

}


NODE* Insert(NODE* root,int data)
{
    if(root == NULL)
    {
        root = (NODE*)malloc(sizeof(NODE));
        root->data = data;
        root->left = root->right = NULL;
    }

    else if(data <= root->data)
    {
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right = Insert(root->right,data);
    }

    return root;

}


int Search(NODE* root,int data)
{

    if(root->data == data)
        return 1;
    else if(root == NULL)
        return 0;
    else if(data<= root->data)
        return Search(root->left,data);
    else
        return Search(root->right,data);

}


void PostOrder(NODE* root)
{

    if(root == NULL)
        return;

    PostOrder(root->left);

    PostOrder(root->right);

    printf("%d->",root->data);
}
