// Here we discussed about the tehnique of building a inorder traversal from the preorder traversal of the binary tree
#include<iostream>
using namespace std;
class node{
    public:
int data;
node* right;
node* left;
node(int val){
    this->data=val;
    left=right=NULL;
}
};
// function to find the position of current node in the inorder
int searchposition(int inorder[],int start,int end,int current){
// search for current in the inorder
for(int i=start;i<=end;i++){
if(inorder[i]==current){
    return i;
}

}
return -1;
}
// function to make inorder sequence from preorder seqence
node* Maketree(int inorder[],int preorder[],int start,int end){
static int index=0;
// base case 1
if(start>end){
    return NULL;
}

    int current=preorder[index];
    index++;
    node* newnode= new node(current);
    if(start==end){
    return newnode;
}
    int position=searchposition(inorder,start,end,current);
    newnode->left=Maketree(inorder,preorder,start,position-1);
    newnode->right=Maketree(inorder,preorder,position+1,end);
    return newnode;
}
// function to print inorder sequence
void printinorder(node* root){
    if(root==NULL){
        return;
    }
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}
int main(){
        //  1
    //     / \
    //    2   5
//       /\  / \
    //  3  4 6  7
int inorder[]={3,2,4,1,6,5,7};
int preorder[]={1,2,3,4,5,6,7};
// create root 
node* root=Maketree(inorder,preorder,0,6);
printinorder(root);

    return 0;
}
// the output is
// 3 2 4 1 6 5 7
