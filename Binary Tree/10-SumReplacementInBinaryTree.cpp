// Here we dicussed about the problem sum replacement

// We need to replace each node with the sum of its data + sum of its left and right subtree 

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
// function to sum replace at every node
node* SumReplace(node* root){
    if(root==NULL){
        return NULL;
    }
   SumReplace(root->left);
   SumReplace(root->right);
if(root->right){
    root->data+=root->right->data;
}
if(root->left){
    root->data+=root->left->data;
}
}
// function to print inorder
void PrintInorder(node* root){
    if(root==NULL){
        return;
    }
 PrintInorder(root->left);
 cout<<root->data<<" ";
 PrintInorder(root->right);
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

cout<<"Binary tree before sum replacement "<<endl;
PrintInorder(root);
cout<<endl;
SumReplace(root);
cout<<"Binary tree after sum replacement "<<endl;
PrintInorder(root);

return 0;

}
// The output of the above code is 
// Binary tree before sum replacement 
// 3 2 4 1 6 5 7 
// Binary tree after sum replacement 
// 3 9 4 28 6 18 7 
