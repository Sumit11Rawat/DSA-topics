// Here we discussed about the approach of finding the height of a binary tree
// APPROACH
// 1-we will calculate the height of left subtree and right subtree using recurssion'
// 2-we find the max of left height and right height
// 3-the height will be max+1
// note - we add 1 to include the root of the binary tree in height
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
// function to find the height of the binary tree
int FindHeight(node* root){
if(root==NULL){
    return 0;
}
int left=FindHeight(root->left);
int right=FindHeight(root->right);
return max(left,right)+1;
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
cout<<"The height of the binary tree is "<<FindHeight(root);
    return 0;
}
// The output of the above code is 
// The height of the binary tree is 3
