#include<iostream>
using namespace std;
#include<vector>
const int N=1e5+2;
int visited[N];
vector<int> graph[N];
//  function for dfs traversal
void dfs(int node){
   
    visited[node]=1;
    cout<<node<<" ";
 
    vector<int>::iterator it;
    for(it=graph[node].begin();it!=graph[node].end();it++){
        if(!visited[*it]){
            dfs(*it);
        }
    }

    
    
}
int main(){
    int nvertices,edges;
    cout<<"enter the no of vertex and edges in a graph ";
    cin>>nvertices>>edges;
    for(int i=0;i<nvertices;i++){
        visited[i]=0;
    }
    for(int i=0;i<edges;i++){
        int vertex1,vertex2;
        cout<<"enter the vertexes of graph ";
        cin>>vertex1>>vertex2;
        cout<<"fine"<<endl;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }
    dfs(1);
    
    
    return 0;
}