// In this problem we are given a binary tree which is not BST and we need to recover it to bst
// The algorith is as follow-

// to correct it we make the use of fact that inorder sequence of binary tree is sorted
// for example
// case 1-where incorrect node is not at the adjacent position
// {2,5,20,10,8}
// we will define three pointer first mid last and an extra prev
// store (5 in first) (20 in mid) (8 in last) and the swap first and last
// case 2-where incorrect node in in the adjacent position
// {1,2,4,3,5,6,7,8}
// now we store (4 in first )and (3 in mid) and( last in NULL) and then swap first and mid


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
// in calcpointer function we will traverse the Binary tree in inorder fashion
// and calulate the value first mid last and prev
void calcpointers(node* root,node** first,node** mid,node** last,node** prev){
if(root==NULL){
    return;
}
// first we will recursively call the left subtree
calcpointers(root->left,first,mid,last,prev);
// now we will check if the condition is broke for the first time or second
if( *prev!=NULL && root->data < (*prev)->data){
    // if it is first time then
    if(!*first){
        *first=*prev;
        *mid=root;
    }
    // if the condition is breaking second time then
    else{
        *last= root;
    }
}
    *prev=root;

calcpointers(root->right,first,mid,last,prev);
}
// main function to restore the original BST
void RestoreBST(node* root){
    node* first, *mid, *last, *prev;
    first=mid=last=prev=NULL;
    calcpointers(root, &first , &mid , &last , &prev);
    // case1
    // when inocrrect node is not at its correct position
    if(first&&last){
        swap((first->data),(last->data));
    }
    // case 2 
    // when we get the incorrect node at adjacent position
    if(first&&mid){
        swap(first->data,mid->data);
    }
}
// function to print inorder traversal
void inorder(node* root){
    if(root==NULL){
        return;

    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    // binary tree is
    //        6
    //      /  \
    //     9    3
    //   /  \    \
    //  1    4    13
node* root=new node(6);
root->left=new node(9);
root->right=new node(3);
root->left->left=new node(1);
root->left->right=new node(4);
root->right->right=new node(13);
cout<<"before ";
inorder(root);
RestoreBST(root);
cout<<endl;
cout<<"after ";
inorder(root);
    return 0;
}
// the output is
// before 1 9 4 6 3 13
// after  1 4 3 6 9 13