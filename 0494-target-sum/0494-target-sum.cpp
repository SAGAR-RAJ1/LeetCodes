class Solution {
public:
   vector<vector<int>>dp;
    int solve(vector<int>& nums, int target ,int i){
        
        if(i<0){
            if(target==0)return 1;
            return 0;
        }
       if(dp[i][target]!=-1)return dp[i][target];
        int take = 0;
        int nottake=solve(nums,target,i-1);
        if(nums[i]<=target)take=solve(nums,target-nums[i],i-1);

        return dp[i][target]=take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();

        int sum = 0 ;
        for(auto &a:nums)sum+=a;
        if(sum<abs(target))return 0;
        int find = sum+target;
        if(find%2!=0)return 0;

        find=find/2;
        dp.assign(n,vector<int>(find+1,-1));
        return solve(nums,find,n-1);
    }
};