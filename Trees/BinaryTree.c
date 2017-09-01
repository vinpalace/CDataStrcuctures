#include<stdio.h>
#include<malloc.h>




struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node NODE;

NODE* Insert(NODE* root , int data);
int Search(NODE* root , int searchdata);
NODE* GetNewNode(int data);

NODE* root = NULL;

void main()
{
    int choice = 1 , number ;
    int searchdata , value;
    while(choice)
    {

        printf("\nEnter the number you want to add\n");
        scanf("%d",&number);
        root = Insert(root , number);

        printf("\nDo you want to contine\n");
        scanf("%d",&choice);

    }


    printf("\nEnter a number to Search\n");
    scanf("%d",&searchdata);
    value = Search(root , searchdata);
    if(value==1)
        printf("\nElement has been found\n");
    else
        printf("\nElement not found\n");
}

NODE* Insert(NODE* root , int data)
{

    if(root == NULL)
    {
        root = (NODE*)malloc(sizeof(NODE));
        root -> data = data;
        root -> left = root -> right = NULL;


        //root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left , data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }

    return root;

}

int Search(NODE* root , int data)
{
    if(root == NULL)
        return 0;
    else if(root->data == data)
        return 1;
    else if(data <= root->data)
        return Search(root->left , data);
    else
        return Search(root->right , data);

}

NODE* GetNewNode(int data)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}
