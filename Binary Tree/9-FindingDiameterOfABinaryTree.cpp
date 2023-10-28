// Here we dicussed about finding the diameter of a binary tree

// The diameter/width of a tree is defined as the number of nodes on the
//    longest path between two end nodes. 

// APPROACH
// 1-find the height of left subtree and right subtree
// 2-define a variable maxi that stores the max sum of leftheight and rightheight
// 3-return maxi as the diameter of the binary tree
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
// function to find the diameter of the binary tree as well as height
// Note-Here we have traversed the binary tree once and found the height 
//      and the diameter in one go thus it reduces the time complexity to o(n)
int FindDiameter(node* root, int &maxi){
    if(root==NULL){
        return 0;
    }
    int leftheight=FindDiameter(root->left,maxi);
    int rightheight=FindDiameter(root->right,maxi);
    maxi=max(maxi,leftheight+rightheight);
    return 1+max(leftheight,rightheight);
    
}

int main(){
    //  1
//     / \
//    2   5
//   /\  / \
//  3  4 6  7
// /
//8 
node* root=new node(1);
root->left=new node(2);
root->right=new node(5);
root->left->left=new node(3);
root->left->right=new node(4);
root->right->left=new node(6);
root->right->right=new node(7); 
root->left->left->left=new node(8);
int maxi=0;
FindDiameter(root,maxi);
cout<<"The diameter of the binary tree is "<<maxi;

return 0;

}
// The output of the above code is 
// The diameter of the binary tree is 5
