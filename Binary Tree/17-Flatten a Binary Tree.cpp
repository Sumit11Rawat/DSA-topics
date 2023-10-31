// Here we discused the problem flattening a binary tree
// ->Given a  binary tree ,flattening  means flatten it into linked list
//   in place.After flattening,left of each node should point to NULL 
//   and right should contain next node in preorder sequence

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
// function to flatten binary tree
void FlattenBinaryTree(Node* root){
    // base case
    if(root==NULL||root->left==NULL&&root->right==NULL){
        return;
    }
    // inorder to flat tree chek if roots left is null or not
    // if not then recursivelly call left subtree for flattening 
    if(root->left!=NULL){
        FlattenBinaryTree(root->left);
        // create a temporary node that store root right 
        Node* temp=root->right;
        // move roots left to right side by below substitution
        root->right=root->left;
        // point roots left to NULL as it doesnt exist 
        root->left=NULL;
        // create a temporary node that points to roots right
        Node* chk=root->right;
        // traverse roots right to reach to bottommost node
        while(chk->right!=NULL){
            chk=chk->right;
        }
        // once we reach bottommost just add temp(whih store roots right)
        // roots right(which was earlier left)
      chk->right=temp;
    }
    // now recursivelly call for right subtree for flatenning
    FlattenBinaryTree(root->right);
}

// Functionn to print inorder sequence
void Inorder(Node* root){
    if(root==NULL){
     return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
int main()
{
    //                    1
    //                  /  \
    //                 2    3
    //                /\    /\
    //               4  5  6  7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"The flatten binary tree is "<<endl;
FlattenBinaryTree(root);
Inorder(root);
return 0;
}
// The output of the above code is
// The flatten binary tree is 
// 1 2 4 5 3 6 7
