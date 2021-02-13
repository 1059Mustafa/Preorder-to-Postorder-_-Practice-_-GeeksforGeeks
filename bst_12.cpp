Node* BST(Node* root,int d)
{
    if(root==NULL)
    root= newNode(d);
    else if(root->data >d)
    root->left=BST(root->left,d);
    else
    root->right=BST(root->right,d);
    return root;
}


Node* find(int post[], int size)
{
    if(size==0)
    return NULL;
    Node* root=NULL;
    for(int i=size-1;i>=0;i--)
    root=BST(root,post[i]);
    return root;
}






Node* constructTree(int pre[], int size) 
{
    int index=-1;
    for(int i=1;i<size;i++)
    {
        if(pre[0]<=pre[i])
        {
            index=i;
            break;
        }
    }
    int post[size];
    int count=0;
    for(int i=index-1;i>0;i--)
    {
        post[count++]=pre[i];
    }
    for(int i=size-1;i>=index;i--)
    {
        post[count++]=pre[i];
    }
    post[size-1]=pre[0];
    
    Node* root=find(post,size);
    return root;
}

