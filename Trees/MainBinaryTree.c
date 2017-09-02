#include<stdio.h>
#include<malloc.h>


struct node
{
    int data;
    struct node* left;
    struct node* right;
};


typedef struct node NODE;

NODE* root;


int HeightOfTree(NODE* root);
NODE* Insert(NODE* root,int data);
void InOrderTraversal(NODE* root);
void PreOrderTraversal(NODE* root);
void PostOrderTraversal(NODE* root);
void LevelOrderTraversal(NODE* root);
void PrintThisLevel(NODE* root,int level);

void main()
{

    int choice=1,option;
    int data;
    int temp;

    while(choice)
    {
        printf("\n1.Insert\t2.InOrderTraversal\t3.PreOrderTraversal\t4.PostOrderTraversal\t5.HeightOfTree\t6.LevelOrderTraversal\n");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
            printf("\nEnter the data you want to add to tree\n");
            scanf("%d",&data);

            root = Insert(root,data);
            break;

            case 2:
            printf("\nPerforming InOrderTraversal\n");
            InOrderTraversal(root);

            break;

            case 3:
            printf("\nPerforming PreOrderTraversal\n");
            PreOrderTraversal(root);

            break;

            case 4:
            printf("\nPerforming PostOrderTraversal\n");
            PostOrderTraversal(root);

            break;

            case 5:
            temp = HeightOfTree(root);
            printf("\nThe height_of_tree is %d",temp);

            break;

            case 6:
            LevelOrderTraversal(root);

            break;

            default:
            printf("\nWrong Choice mate\n");


        }

        printf("\nDo you want to continue\n");
        scanf("%d",&choice);
    }

}

NODE* Insert(NODE* root,int data)
{
    if(root == NULL)
    {
        root = (NODE*)malloc(sizeof(NODE));
        root->left = root->right = NULL;
        root->data = data;


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
    if(root == NULL)
        return 0;
    else if(root->data == data)
        return 1;
    else if(data <= root->data)
        return Search(root->left,data);
    else
        return Search(root->right,data);
}


void InOrderTraversal(NODE* root)
{
    if(root == NULL)
        return;

    InOrderTraversal(root->left);

    printf("%d->",root->data);

    InOrderTraversal(root->right);
}


void PreOrderTraversal(NODE* root)
{
    if(root == NULL)
        return;


    printf("%d->",root->data);

    PreOrderTraversal(root->left);

    PreOrderTraversal(root->right);
}

void PostOrderTraversal(NODE* root)
{
    if(root == NULL)
        return;


    PostOrderTraversal(root->left);

    PostOrderTraversal(root->right);

    printf("%d->",root->data);
}

int HeightOfTree(NODE* root)
{
    if(root == NULL)
        return 0;


    int leftTreeHeight , rightTreeHeight;

    leftTreeHeight = HeightOfTree(root->left);
    rightTreeHeight = HeightOfTree(root->right);

    if(leftTreeHeight>rightTreeHeight)
        return leftTreeHeight+1;
    else
        return rightTreeHeight+1;
}

void LevelOrderTraversal(NODE* root)
{

    int i, height_of_tree;
    height_of_tree = HeightOfTree(root);

    for(i = 1;i<=height_of_tree;i++)
    {
        PrintThisLevel(root,i);
    }

}

void PrintThisLevel(NODE* root,int level)
{
    if(root==NULL)
        return;
    else if(level == 1)
        printf("%d->",root->data);

    else
    {
        PrintThisLevel(root->left,level-1);
        PrintThisLevel(root->right,level-1);
    }

}
