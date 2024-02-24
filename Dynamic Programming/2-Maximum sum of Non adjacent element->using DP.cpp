#include <bits/stdc++.h> 

//  recursive soln -->giving tle

// int chk(vector<int>&nums,int k){
//        if(k>=nums.size()){
//         //  fans=max(fans,sum);
//          return 0;
//        }
//        if(k==nums.size()-1){
//          return nums[k];
//        }
//       //  sum+=nums[k];

      
//        int incl=chk(nums,k+2)+nums[k];
//        int excl= chk(nums,k+1);
//       return max(incl,excl);


// }

// dp-->memoisation
int Memoisation(vector<int>&nums,vector<int>&dp,int k){
 if(k>=nums.size()){
        //  fans=max(fans,sum);
         return 0;
       }
       if (k == nums.size() - 1) {
         return nums[k];
       }
       //  sum+=nums[k];
       if (dp[k] != -1)
         {
           return dp[k];
         }

       int incl=Memoisation(nums,dp,k+2)+nums[k];
       int excl= Memoisation(nums,dp,k+1);
       
      dp[k]=max(incl,excl);
      return dp[k];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int ind=0;
    int sum=0;
    vector<int>dp(nums.size()+1,-1);
   return  Memoisation(nums,dp,ind);
  
}
