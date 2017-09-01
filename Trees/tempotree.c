struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

NODE *root,*newnode;


NODE* GetNewNode(int data)
{
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

NODE* Insert(*root,int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
        //return root;
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

int Search(*root , int data)
{
    if(root==NULL)
        return 0;
    else if(root->data==data)
        return 1;
    else if(data<=root->data)
        return Search(root->left,data);
    else
        return Search(root->right,data);
}

int main()
{
    root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,50);
    root = Insert(root,11);
    root = Insert(root,8);

}
