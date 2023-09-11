// In this code will be searching a particular key in a binary search tree
// considering a maxheap
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
node* SearchInBst(node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(key<root->data){
        return SearchInBst(root->left,key);
    }
    return SearchInBst(root->right,key);


}
int main(){
    // the bst is 
    //     5
    //   /   \
mm  // 4     7
//    /      /
//  3       6
node* root=new node(5);
root->left=new node(4);
root->right=new node(7);
root->left->left=new node(3);
root->right->left=new node(6);
int key;
cout<<"Enter the key to search in BST :";
cin>>key;
if(SearchInBst(root,key)){
    cout<<key<<" is present in given BST "<<endl;

}
else{
    cout<<key<<" is not present in given BST "<<endl;
}
    return 0;
}