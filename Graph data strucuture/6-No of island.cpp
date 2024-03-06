class Solution {
    // a bfs function for bfs traversal
    void bfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j){
        // mark the incoming cell as visited
         vis[i][j]=1;
         int n=grid.size();
         int m=grid[0].size();
        //  create queue of pair to store row and column of cell
         queue<pair<int,int>>q;
        //  push it in the queue
         q.push({i,j});
        //  now iterate in the queue until its empty 
        
         while(!q.empty()){
            //  pick each front element of the queue and traverse its eight side
            // then pop it out
            // similarly iterate for the next queue front
             int r=q.front().first;
             int c=q.front().second;
             q.pop();
            //  now traverse to the eight direction of cell by bleow loops
            for(int k=-1;k<=1;k++){
                for(int l=-1;l<=1;l++){
                    // below condition are necesarry so that we get right cells visited
                    
                    if(r+k>=0&&r+k<n&&c+l>=0&&c+l<m&&grid[r+k][c+l]=='1'&&!vis[r+k][c+l]){
                    //  mark the cells visited and then push it inside the queue
                       vis[r+k][c+l]=1;
                       q.push({r+k,c+l});
                    }
                   
                }
            }
         }
        
    }
  public:
  
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        // create a vector of vector to store visited cells of matrix
        vector<vector<int>>vis(n,vector<int>(m,0));
        // traverse through each cell and call bfs from the first cell where 
        // there is land and it is unvisited i.e being visited first
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(!vis[i][j]&&grid[i][j]=='1'){
                   count++;
                //   bfs called for the first cell
                   bfs(grid,vis,i,j);
               }
           }
       }
       return count;
    }
};
