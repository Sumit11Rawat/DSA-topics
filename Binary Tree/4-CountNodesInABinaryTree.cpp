// In this section we count the no of nodes present in a binary tree
#include<iostream>
using namespace std;
class node{
public:
int data;
node* left;
node* right;
node(int data){
    this->data=data;
    left=NULL;
    right=NULL;
}
};
int countnode(node* root){
    // base case
    if(root==NULL){
        return 0;
    }
    // recursive relation
    return countnode(root->right)+countnode(root->left)+1;
}
int main(){
    //  1
//     / \
//    2   5
//   /\  / \
//  3  4 6  7
node* root=new node(1);
root->left=new node(2);
root->right=new node(5);
root->left->left=new node(3);
root->left->right=new node(4);
root->right->left=new node(6);
root->right->right=new node(7);
cout<<"the no of nodes present in binary tree are "<<countnode(root);
    return 0;
}
// The output is 
// the no of nodes present in binary tree are 7
