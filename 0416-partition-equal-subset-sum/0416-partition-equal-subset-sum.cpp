class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int>& nums, int i, int target) {
        if (i == 0) {
            return nums[i] == target;
        }
        if (dp[i][target] != -1)
            return dp[i][target];
        bool nottake = solve(nums, i - 1, target);
        bool take = false;
        if (nums[i] <= target)
            take = solve(nums, i - 1, target - nums[i]);

        return dp[i][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto& a : nums) sum += a;
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        dp.assign(n, vector<int>(sum + 1, -1));
        return solve(nums, n - 1, target);
    }
};