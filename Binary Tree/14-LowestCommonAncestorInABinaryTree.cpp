// Here we dicussed about the problem of finding the lowest common ancestor
// LCA of two nodes is the closest node which is parent of both the nodes
#include<queue>
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};

// function to find the lowest common ancestor of two nodes
node* LCA(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    // check if while traversing node we found the two nodes whose lca is to be found
//   if found return the node at which they are present
    if(root->data==n1||root->data==n2){
        return root;
    }
    // traverse left subtree
    node* left=LCA(root->left,n1,n2);
    // traverse right subtree
    node* right=LCA(root->right,n1,n2);
    // find the correct node which represent lca using following condition
    // if the node at which we are standing has left and right both not equal to NULL
    // it means one no is present at its left while other on its right
    if(left!=NULL&&right!=NULL){
        return root;
    }
    // if left subtree is NULL check for nodes in the right subtree
    if(left==NULL){
        return LCA(root->right,n1,n2);
    }
    // if right subtree is NULL check for nodes in the left subtree
    if(right==NULL){
        return LCA(root->left,n1,n2);
    }
    // if both left and right are NULL it means that nodes re not present in the tree
    // so return NULL
    if(left==NULL&&right==NULL){
        return NULL;
    }
    
}
int main(){
    //  1
//     / \
//    2   5
//   /\  / \
//  3  4 6  7
// /
// 8
node* root=new node(1);
root->left=new node(2);
root->right=new node(5);
root->left->left=new node(3);
root->left->right=new node(4);
 root->right->left=new node(6);
 root->right->right=new node(7); 
 root->left->left->left=new node(8);
//  since LCA return a node so we use LCA->data for the lca 
 cout<<"The Lowest Common Ancestor is :"<<LCA(root,3,4)->data<<endl;
cout<<"The Lowest Common Ancestor is :"<<LCA(root,8,7)->data<<endl;
return 0;

}
// The output of the above code is 
// The Lowest Common Ancestor is :2
// The Lowest Common Ancestor is :1
