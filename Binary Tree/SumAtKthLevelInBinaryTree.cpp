// Here we discuss the approach of finding the sum of all nodes at a particular level
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
class node
{
public:
int data;
node* left;
node* right;
node(int data){
    this->data=data;
    left=NULL;
    right=NULL;
}
};

void LevelOrderTraversal(node *root,int level)
{
    if (root == NULL) 
    {
        return;
    }
//   create queue to store level order nodes
    queue<node *> q;
     
    // create a node that stores the front element of the queue
    node *curr;
 
    // Enqueue Root 
    q.push(root);
    // create a variable to store level in binary tree

   int chk=0;
   int sum=0;
 
    while (!q.empty())
    {
        
        

        int size=q.size();
         
        for(int i=0;i<size;i++){
             curr = q.front();

            if(chk==level){
            sum+=curr->data;
        }
            
        q.pop();
            // pushing left child of current node to queue if its not NULL
            
            if(curr->left){
            q.push(curr->left);
            }
            // pushing right child of current node to queue if its not NULL
            
            if(curr->right){
            q.push(curr->right);
            }
            
        }
        chk++;
    }
    cout<<"the sum at level "<<level<<" is "<<sum;
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
int level=2;
LevelOrderTraversal(root,level);
return 0;
}
// The output of the above code is
// the sum at level 2 is 20         
