// Here we dicussed about the problem of finding whether a binary tree is balanced or not

// A Binary Tree is called balanced is the absolute difference of height of 
//   left subtree and right subtree is less than or equal to one


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
// function  to find the height of the binary tree
int TreeHeight(node* root){
    if(root==NULL){
        return 0;
    }
return TreeHeight(root->left)+TreeHeight(root->right)+1;
}
// function to check whether binary tree is balanced or not
bool isBalanced(node* root){
    if(root==NULL){
        return true;
    }


    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }
int leftheight=TreeHeight(root->left);
int rightheight=TreeHeight(root->right);
    if(abs(leftheight-rightheight)>=1){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    //  1
//     / 
//    2   
//   /\   
//  3  4  

node* root=new node(1);
root->left=new node(2);
// root->right=new node(5);
root->left->left=new node(3);
root->left->right=new node(4);
// root->right->left=new node(6);
// root->right->right=new node(7); 
if(isBalanced(root)){
    cout<<"The binary tree is balanced ";
}
else{
    cout<<"The binary tree is unbalanced ";
}
return 0;
}
// The output of the above code is 
// The binary tree is unbalanced
