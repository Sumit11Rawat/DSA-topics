// In this code we will be discussing whether a binary search treee is valid or not 


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
bool IsValid(node* root,int minval,int maxval){
// base case
if(root==NULL){
    return true;
}
// if at any point any of these two condition are broken that means its not a valid BST
if(root->data>=maxval||root->data<=minval){
    return false;
}
// now iterate for the left and right subtree
// for left subtree min val will remain same but max value will become roots data
// for right subtree min val will become roots data and max will remain same
// return true only when both left and right return true
return (IsValid(root->left,minval,root->data) && IsValid(root->right,root->data,maxval));
}

int main(){
 // creating a BST
 // the bst is 
    //     
    //   /   \
    // 4     7
//    /      /
//  3       6
node* root= new node(2);
root->left=new node(4);
root->right=new node(7);
root->left->left=new node(3);
root->right->left=new node(6);
if(IsValid(root,INT32_MIN,INT32_MAX)){
    cout<<"Valid BST ";
}
else{                                                       
    cout<<"Invalid BST";
}
    return 0;
}