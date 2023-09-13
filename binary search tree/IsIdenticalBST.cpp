// In this code we will be discussing the whether two BST are identical or not
// for two BST to be identical they must be structurally as well as value wises equal

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
// function for identical bst
bool IsIdenticalBST(node* root1,node* root2){
    // base case
    if(root1==NULL&&root2==NULL){
        return true;
    }
    else if(root1==NULL||root2==NULL){
        return false;
    }
    // here we will check three conditions
    // if all three are simultaneously then only it is a identical bst
    else{
        bool cond1=root1->data==root2->data;
        // recursively checking for the left subtree for both tree
        bool cond2=IsIdenticalBST(root1->left,root2->left);
        //  recursively checking for the right subtree for both tree
        bool cond3=IsIdenticalBST(root1->right,root2->right);
    
    if(cond1 && cond2 && cond3){
        return true;
    }
    else{
        return  false;
    }
}
}
int main(){
 // creating a BST
 // the bst is 
    //     5
    //   /   \
    // 4     7
//    /      /
//  3       6
node* root= new node(5);
root->left=new node(4);
root->right=new node(7);
root->left->left=new node(3);
root->right->left=new node(6);
// creating second bst
//       2
//      /  \
//     1    3
node* root1=new node(2);
root1->left=new node(1);
root->right=new node(3);
if(IsIdenticalBST(root,root)){
    cout<<"Identical BST";
}
else{
    cout<<"Unidentical BST";
}
cout<<endl;

if(IsIdenticalBST(root,root1)){
    cout<<"Identical BST";
}
else{
    cout<<"Unidentical BST";
}


    return 0;
}
// output is 
// Identical BST
// Unidentical BST