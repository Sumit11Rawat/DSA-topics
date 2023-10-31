// Here we discused the problem of finding the max sum path in a binary tree

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
     Node *left;
     Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// function for max sum path
int MaxSumPath(Node* root,int &maxi){
    if(root==NULL){
        return 0;
    }
    int left=MaxSumPath(root->left,maxi);
    int right=MaxSumPath(root->right,maxi);
    maxi=max(maxi,root->data+left+right);
    return root->data+max(left,right);
}
int main()
{
    //                    1
    //                  /  \
    //                 2    3
    //                /\    /\
    //               4  5  6  7
    //              /
    //             8
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left=new Node(8);
    int maxi=0;
   
MaxSumPath(root,maxi);
cout<<"Max sum path is "<<maxi;
return 0;
}
// The output of the above code is
// Max sum path is 25
