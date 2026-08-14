class Solution {
public:
    int count = 0;
    vector<vector<int>>dp;
    void solve(vector<int>& nums, int target, int sum, int i) {

        if (i < 0) {
            if (sum == target) {
                count++;
            }
            return;
        }
        solve(nums, target, sum + nums[i], i - 1);
        solve(nums, target, sum - nums[i], i - 1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        solve(nums,target,0,n-1);
        return count;
    }
};