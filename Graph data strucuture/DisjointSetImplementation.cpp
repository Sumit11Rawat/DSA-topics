// In this code we implemented disjoint set with path compression and union by rank
// DISJOINT SET
// -->>a data structure that store non overlapping or disjoint subset of element is
//     called disjoint set data structure

// -->>two set are called disjoint if they dont have any element in common that is 
//      intersection of set is a null set
//    FOLLOWING ARE OPERATION SUPPORTED BY DISJOINT SET
//   -->adding new set to the disjoint set
//   -->>merging two or more disjoint set using union operation
//   -->>find parent of nodes using find operation
//   -->>check if two sets are disjoint or not
#include<iostream>
using namespace std;
class disjoint{
int* rank;
int* parent;
int n;
public:
disjoint(int n){
    rank= new int[n];
    parent=new int [n];
    this->n=n;
    makeset();
    }

void makeset(){
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
}
int findparent(int node){
    if(parent[node]==node){
       return node;
    }
    return parent[node]=findparent(parent[node]);
}

void UnionSET(int u,int v){
     u=findparent(u);
     v=findparent(v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
parent[v]=u;
    }
    else{
        parent[u]=v;
        rank[v]++;
    }
}
};
int main(){
disjoint obj(8);
obj.UnionSET(0,1);
obj.UnionSET(1,2);
obj.UnionSET(2,3);
obj.UnionSET(4,6);

cout<<" operation output of disjoint set are "<<endl;
if(obj.findparent(3)==obj.findparent(0)){
    cout<<"yes "<<endl;
}
else{
    cout<<"no"<<endl;
}
if(obj.findparent(4)==obj.findparent(1)){
    cout<<"yes ";
}
else{
    cout<<"no";
}

    return 0;
}
// the output of the above code is-> 
//     operation output of disjoint set are 
//     yes
//     no