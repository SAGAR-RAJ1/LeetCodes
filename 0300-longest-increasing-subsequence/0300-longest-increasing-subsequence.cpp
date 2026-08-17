class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int i , int prev){
        if(i<0)return 0;

        if(dp[i][prev]!=-1)return dp[i][prev];
        //take
         int take = 0;
         if(prev==nums.size() || nums[i]<nums[prev])take = 1+solve(nums,i-1,i);
        //not take
        int nottake = solve(nums,i-1,prev);

        return dp[i][prev]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n,vector<int>(n+1,-1));
        return solve(nums,n-1,n);

    }
};