#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    // constructor
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
node* insertBST(node* root,int val){
    // base case
if(root==NULL){
    return new node(val);
}
// check recursively for the left subtree
if(val<root->data){
    root->left=insertBST(root->left, val);
}
// check recursively for the right subtree
else{
    root->right=insertBST(root->right,val);
}
return root;


}
// printing the inorder flow of bst
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
node* root=NULL;
root=insertBST(root,5);
insertBST(root,4);
insertBST(root,3);
insertBST(root,2);
insertBST(root,1);

cout<<"The created BST is ";
inorder(root);
return 0;

}


// the output is 
// The created BST is 1 2 3 4 5