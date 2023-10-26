
// Here we discussed about the technique of building inorder traversal from postorder traversal
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
node* Maketree(int inorder[],int postorder[],int start,int end){
static int index=6;
// base case 1
if(start>end){
    return NULL;
}

    int current=postorder[index];
    index--;
    node* newnode= new node(current);
    if(start==end){
    return newnode;
}
    int position=searchposition(inorder,start,end,current);
    // note -we will first create the right subtree of inorder bcoz 
    //       while traversing the postorder from last we first encounter root  node
    //       and them the right subtree then left subtree
    
    newnode->right=Maketree(inorder,postorder,position+1,end);
    newnode->left=Maketree(inorder,postorder,start,position-1);
    
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
int inorder[]={3,2,4,1,6,5,7};
int postorder[]={3,4,2,6,7,5,1};
// create root 
node* root=Maketree(inorder,postorder,0,6);
printinorder(root);

    return 0;
}

// The output is 
// 3,2,4,1,6,5,7
