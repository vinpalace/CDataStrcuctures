#include<stdio.h>
#include<malloc.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


typedef struct Node NODE;


NODE *root = NULL;
NODE* Insert(NODE *root , int data);
int Search(NODE* root,int data);

NODE* GetNewNode(int data)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}


int main()
{
    root = Insert(root,15);
    root = Insert(root,20);
    root = Insert(root,30);
    root = Insert(root,34);
    root = Insert(root,46);
    root = Insert(root,13);
    root = Insert(root,54);

    int number;
    printf("\nEnter a number to be searched\n");
    scanf("%d",&number);
    if(Search(root,number)==1)
        printf("\nFound\n");
    else
        printf("\nNotfound\n");

}


NODE* Insert(NODE* root, int data)
{
    if(root == NULL) //if tree is empty
    {
        root = GetNewNode(data);

    }
    else if(data <= root->data)
    {
        root -> left = Insert(root->left,data);

    }
    else
    {
        root -> right = Insert(root->right,data);
    }
    return root;
}


int Search(NODE* root , int data)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->data == data)
    {
        return 1;
    }
    else if(data <= root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}
