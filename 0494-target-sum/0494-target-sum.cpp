class Solution {
public: 
     vector<vector<int>>dp;
    int solve(vector<int>& nums, int target, int i) {

        if (i < 0) {

            if (target == 0)
                return 1;
            return 0;
        }
        if(dp[i][target]!=-1)return dp[i][target];
        int notpick = solve(nums, target, i - 1);
        int pick = 0;
        if (nums[i] <= target)
            pick = solve(nums, target - nums[i], i - 1);

        return dp[i][target]=pick + notpick;
    }
    int findTargetSumWays(vector<int>& nums, int diff) {
        int sum = 0;
        int n = nums.size();

        for (auto& a : nums)
            sum += a;
       
        if (sum < abs(diff) || (sum + diff) % 2 == 1)
            return 0;
        int target = (sum + diff) / 2;
        dp.assign(n,vector<int>(sum+1,-1));

        return solve(nums, target, n - 1);
    }
};