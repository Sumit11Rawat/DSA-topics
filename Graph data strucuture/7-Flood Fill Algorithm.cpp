
class Solution {
public:
// a simple dfs function for depth traversal
    void dfs(vector<vector<int>>& image,vector<vector<int>>&ans,int newColor,int oldcolor,int sr,int sc){
        //   mark the incoming cell with new color
          ans[sr][sc]=newColor;
          int n=image.size();
          int m=image[0].size();
        //   store delrow and delcol for 4 direction traversal
          int delrow[]={-1,0,1,0};
          int delcol[]={0,1,0,-1};
        //   now start iterating in the 4 direction of given cell
          for(int i=0;i<4;i++){
              int nrow=sr+delrow[i];
              int ncol=sc+delcol[i];
            //   chk the boundary condition for row and column
            // chk if the cell has same colour as given cell and its colour is old as well
              if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]==oldcolor&&ans[nrow][ncol]!=newColor){
                //   recursilvely traverse depth wise for neighbour cells
                  dfs(image,ans,newColor,oldcolor,nrow,ncol);
              }
              
          }
          
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    //   create new matrix to store final ans
       vector<vector<int>>ans=image;
    //   store the color of given pixel
       int oldcolor=image[sr][sc];
    //   call dfs for the given pixel so that it can mark its adjacent cells as well
       dfs(image,ans,newColor,oldcolor,sr,sc);
    
       return ans;
    }
};

