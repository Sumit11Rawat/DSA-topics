// Here we discused the problem finding all nodes at distance k

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
     Node *left;
     Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// function to print node at distance k downward
void PrintNodeDownward(Node* root,int k){
    if(root==NULL||k<0){
        return;
    }
    // if we get k=0 means we have reached our required answer
    if(k==0){
        cout<<root->data<<" ";
    }
    //  traverse left and right subtree
    PrintNodeDownward(root->left,k-1);
    PrintNodeDownward(root->right,k-1);

}
// main function to print all node at distance k
int PrintNodeAtDistanceK(Node* root,Node* target,int k){
    // base case
if(root==NULL){
    return -1;
}
if(root==target){
    PrintNodeDownward(root,k);
    return 0;
}
// now recursivley travel left subtree
int d1=PrintNodeAtDistanceK(root->left,target,k);
// check whether target was found in left part 
if(d1!=-1){
// if found check if root is at distance k from target
// here d1 represent distance of roots left node from target
if(d1+1==k){
    // that means we found root at distance k from root
    // print roots data
    cout<<root->data<<endl;
}
else{
    // else go for the roots right subtree

    PrintNodeDownward(root->right,k-d1-2);
}
return d1+1;
}
// replicate same for right subtree
int d2=PrintNodeAtDistanceK(root->right,target,k);
if(d2!=-1){
    if(d2+1==k){
        cout<<root->data<<endl;
    }
    else{
        PrintNodeDownward(root->left,k-d2-2);
    }
    return d2+1;
}

// if target not present either in left or in right return -1
return -1;
}

int main()
{
    //                    1
    //                  /  \
    //                 2    3
    //                /\    /\
    //               4  5  6  7
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
PrintNodeAtDistanceK(root,root->left,1);
PrintNodeAtDistanceK(root,root->left->right,2);
return 0;
}
// The output of the above code is
// 4 5 1
// 4 1
