#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* InsertBST(Node *root,int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }
    if(val<root->data )
    {
        root->left = InsertBST(root->left,val);
    }
    else
    {
        root->right = InsertBST(root->right,val);
    }
    return root;
}

void Inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main(int argc, char const *argv[])
{
    Node* root = NULL;
    root = InsertBST(root,7);    
    InsertBST(root,1);    
    InsertBST(root,2);    
    InsertBST(root,4);    
    InsertBST(root,3);    
    InsertBST(root,8);  
    Inorder(root);
    cout<<endl;  
    return 0;
}

