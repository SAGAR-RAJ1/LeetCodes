class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        unordered_map<int, int> m;

        for (auto& a : nums) {
            m[a]++;
        }

        int n = nums.size();

        // k = 1
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                if (m[nums[i]] == 1) {
                    maxi = max(maxi, nums[i]);
                }
            }

            return maxi == INT_MIN ? -1 : maxi;
        }

        // k = n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // 1 < k < n
        if (m[nums[n - 1]] == 1 && m[nums[0]] == 1) {
            return max(nums[0], nums[n - 1]);
        }
        else if (m[nums[n - 1]] == 1) {
            return nums[n - 1];
        }
        else if (m[nums[0]] == 1) {
            return nums[0];
        }

        return -1;
    }
};