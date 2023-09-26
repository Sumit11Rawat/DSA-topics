#include<iostream>
using namespace std;
#include<limits.h>

int minkey(int key[],bool MSTset[]){
int min=INT_MAX;
int min_index;
for(int i=0;i<9;i++){
    if(MSTset[i]==false&&key[i]<min){
        min=key[i];
        min_index=i;
    }
}
return min_index;
}
// printing the tree
void printMST(int parent[], int graph[9][9])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < 9; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
void PrimsMST(int graph[][9]){
// array to store parent;
int parent[9];
// key array used to store minimum weight edges data
int key[9];
// to represent set of vertices included in mst
bool MSTset[9];
// intialise all key as infinite and then we will update this
for(int i=0;i<9;i++){
    key[i]=INT_MAX;
    MSTset[i]=false;
}
// alway include first vertex in MST
// set parent of 0 as -1
key[0]=0;
parent[0]=-1; 
for(int i=0;i<9;i++){
    int u=minkey(key,MSTset);
    MSTset[u]=true;

    for(int i=0;i<9;i++){
        if(graph[u][i]&&MSTset[i]==false&&graph[u][i]<key[i]){
            parent[i]=u;
            key[i]=graph[u][i];
        }
    }
}
printMST(parent, graph);

}
int main(){
int graph[9][9] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    PrimsMST(graph);
 
    return 0;


    return 0;
}