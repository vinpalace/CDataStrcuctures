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
void LevelOrder(NODE* root);
void PrintAtLevel(NODE* root,int level);
int height(NODE* root);

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

    LevelOrder(root);

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

int height(NODE* root)
{
    if(root==NULL)
        return 0;

    else
    {
        int left_height = height(root->left);
        int right_height = height(root->right);

        if(left_height > right_height)
            return left_height+1;
        else
            return right_height+1;


    }
}


void LevelOrder(NODE* root)
{
    int height_of_tree = height(root);

    int i ;

    for(i=1;i<=height_of_tree;i++)
        PrintAtLevel(root,i);
}


void PrintAtLevel(NODE* root,int level)
{
    if(root==NULL)
        return;
    else if(level==1)
        printf("%d->",root->data);

    else
    {
        PrintAtLevel(root->left,level-1);
        PrintAtLevel(root->right,level-1);
    }
}
