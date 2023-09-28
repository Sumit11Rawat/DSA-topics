//        KRUSKALS ALGORITHM
// In this code we will discuss about the kruskals algorithm to find minimum spanning tree
// spanning tree->- A spanning tree is the subgraph of an undirected connected graph.
// minimum spanning tree-> Minimum spanning tree can be defined as the spanning tree 
//                         in which the sum of the weights of the edge is minimum.


// How does Kruskal's algorithm work?
//       In Kruskal's algorithm, we start from edges with the lowest weight and 
//       keep adding the edges until the goal is reached
//   step 1->First, sort all the edges from low weight to high.
//   step 2->Now, take the edge with the lowest weight and add it to
//           the spanning tree. If the edge to be added creates a cycle, then reject the edge.
//   step3-> Continue to add the edges until we reach all vertices, and a minimum spanning tree is created.

#include<iostream>
using namespace std;
#include<algorithm>
#include<utility>
const int MAX = 1e4 + 5;
int parent[MAX],nodes,edges;
pair <long long, pair<int, int> >  Pair[MAX];
void SetParent(){
    for(int i=0;i<MAX;i++){
        // intially set parent of every node to itself
        parent[i]=i;
    }
}
int findparent(int node){
    if(parent[node]==node){
       return node;
    }
    return parent[node]=findparent(parent[node]);
}
void Union(int x,int y){
    int p = findparent(x);    
    int q = findparent(y);    
parent[p] = parent[q]; 
}
long long Kruskal(pair<long long ,pair<int,int>>p[]){
    int  weight,minweight=0;
    int x,y;
    for(int i=0;i<edges;i++){
        x=Pair[i].second.first;
        y=Pair[i].second.second;
        weight=Pair[i].first;
        
    }
    if(findparent(x)!=findparent(y)){
        minweight+=weight;
        Union(x,y);
    }
    return minweight;
}
int main(){
        int x, y;    
    long long weight, minimumCost,wt;    

    cout <<"Enter Nodes and edges";    
    cin >> nodes >> edges;    
    for(int i = 0;i < edges;++i)    
    {    
        cout<<"Enter the value of X, Y and edges";    
    cin >> x >> y >> wt;    
        Pair[i] = make_pair(wt, make_pair(x, y));    
    }    
      SetParent();  
    sort(Pair, Pair + edges);   
    minimumCost=Kruskal(Pair);
    cout<<"the minimum cost is "<<minimumCost;
    
    return 0;
}
// the output of above code is 
//    Enter Nodes and edges5 7
//    Enter the value of X, Y and edges1 2 1
//    Enter the value of X, Y and edges1 3 7
//    Enter the value of X, Y and edges1 4 10
//    Enter the value of X, Y and edges1 5 5
//    Enter the value of X, Y and edges2 3 3
//    Enter the value of X, Y and edges3 4 4
//    Enter the value of X, Y and edges4 5 2
//    the minimum cost is 10