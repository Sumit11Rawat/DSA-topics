// Here we discussed about the problem of finding the smallest distance between two nodes
// APPROACH-
//  1->find the lca of two given node
// 2->find the distance of both node from lca 
// 3->return the sum of distance

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

// function to find the height of given node from root(which is lca)
int findDist(Node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        return dist;
    }
    int left = findDist(root->left, k, dist + 1);
    if (left!=-1)
    {
        return left;
    }
    return findDist(root->right, k, dist + 1);
}


// function to find the lowest common ancestor
Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}
// function to return distance between two nodes
int distBtwnNodes(Node *root, int n1, int n2)
{
    // we store root given by LCA function in lca 
    Node *lca = LCA(root, n1, n2);
    // now we find distance between root(which is lca) and given node 
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    return d1 + d2;
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
int n1=2;
int n2=3;
cout <<"The smalles distance between node "<<n1<<" and "<<n2<<" is "<<distBtwnNodes(root, n1,n2)<<endl;
n1=2;
n2=7;
cout <<"The smalles distance between node "<<n1<<" and "<<n2<<" is "<<distBtwnNodes(root, n1,n2);
return 0;
}
// The output of the above code is
// The smalles distance between node 2 and 3 is 2
// The smalles distance between node 2 and 7 is 3
