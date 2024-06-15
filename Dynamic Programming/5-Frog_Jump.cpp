// using memoisation

#include <bits/stdc++.h> 
int min_energy(int n ,vector<int>&heights,vector<int>&dp,int ind,int result){
   if(ind==0){
       return 0;
   }
   if(dp[ind]!=-1){
       return dp[ind];
   }
   int left=min_energy(n,heights,dp,ind-1,result)+abs(heights[ind]-heights[ind-1]);
  
   int right=INT_MAX;
   if (ind > 1) {
        right = min_energy(n, heights, dp, ind - 2,result) +
                   abs(heights[ind] - heights[ind - 2]);
   }
 
  return dp[ind] =min(left,right);

   
}
int frogJump(int n, vector<int> &heights)
{
   vector<int>dp(n+1,-1);
   int ind=n-1;
   int result=0;
   return min_energy(n-1,heights,dp, ind,result);
}



// using tabulation method

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // using tabulation method
    vector<int>dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int left=dp[i-1]+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1){
         right=dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(left,right);
    }
    return dp[n-1];
}
