#include <bits/stdc++.h>
int mod = 1e9 + 7;
int cal(int n,vector<int>&dp){
    if(n==0){
      return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
   dp[n]= (cal(n-2,dp)+cal(n-1,dp))%mod;
   return dp[n];
}
int countDistinctWays(int nStairs) {
    vector<int>dp(nStairs+1,-1);
  return cal(nStairs,dp);

}
