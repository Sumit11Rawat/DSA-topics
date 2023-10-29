// Here we dicussed about the problem printing the right view of a binary tree
// APPROACH-
//   the approach is similar to level order traversal
//   here we will just print the last element of every level which will serve as rightmost element in every level
#include<queue>
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

// function to print right view of a binary tree
void leftview(node* root){
    if(root==NULL){
        return ;
    }

queue<node*> q;
q.push(root);
   while(!q.empty()){

int n=q.size();
    for(int i=0;i<n;i++){
        
        node* current=q.front();
        q.pop();
        if(i==n-1){
            cout<<current->data<<" ";
        }
     if(current->left){
        q.push(current->left);
     }
     if(current->right){
        q.push(current->right);
     }
    }
   }
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
 cout<<"The left view of binary tree is ";
leftview(root);

return 0;

}
// The output of the above code is 
// The left view of binary tree is 1 5 7
