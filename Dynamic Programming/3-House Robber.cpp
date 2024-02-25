class Solution {
public:
int chk(vector<int>&nums,int k,vector<int>&dp){
    if(k>=nums.size()){
        return 0;
    }
    if(k==nums.size()-1){
        return nums[k];
    }
    if(dp[k]!=-1){
        return dp[k];
    }
    int incl=chk(nums,k+2,dp)+nums[k];
    int excl=chk(nums,k+1,dp);
    dp[k]=max(incl,excl);
    return dp[k];
}
    int rob(vector<int>& nums) {
        int ind=0;
        vector<int>dp(nums.size()+1,-1);
        return chk(nums,ind,dp);
    }
};
