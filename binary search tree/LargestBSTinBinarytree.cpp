// In this code we will be discussing how to find the size of the 
// largest valid BST in binary tree
#include <bits/stdc++.h>
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
// create a structure to store five info for every node
class Info{
    public:
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
Info largestBSTinBT(node* root){
    if(root==NULL){
        return {0, INT_MAX , INT_MIN , 0, true};
    }
    // base case if root is leaf node
    if(root->left==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
        
    }
    // now we will call recursively in left and right subtree of binary tree
    Info leftinfo=largestBSTinBT(root->left);
    Info rightinfo=largestBSTinBT(root->right);
    // now we will define a current variable in info that define 
    // the values of current level root
    Info current;
 current.size=1+leftinfo.size+rightinfo.size;
//  now we will check if left and right subree are forming bst
// if yes then we will move towards current
if(leftinfo.isBST && rightinfo.isBST && leftinfo.max<root->data && rightinfo.min>root->data){
// now updating the value of current elment
current.min=min(leftinfo.min,root->data);
current.max=max(leftinfo.max,root->data);
current.ans = leftinfo.ans+rightinfo.ans+1;
current.isBST=true;
return current;
}
else{
current.ans=max(leftinfo.ans,rightinfo.ans);
current.isBST=false;
return current;
}


}
int main(){
node* root= new node(5);
root->left=new node(4);
root->right=new node(7);
root->left->left=new node(3);
root->right->left=new node(6);

cout<<"largest bst in bt is "<<largestBSTinBT(root).ans;
    return 0;
}

// Output is 
// largest bst in bt is 5