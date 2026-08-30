class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int minindex =
            min_element(nums.begin(), nums.end()) - nums.begin();

        int maxindex =
            max_element(nums.begin(), nums.end()) - nums.begin();

        multiset<int> value;

        value.insert(abs(maxindex - minindex));
        value.insert(1 + min(maxindex, minindex));
        value.insert(n - max(maxindex, minindex));

        auto it = value.begin();

        int ans = *it;

        it++;

        ans += *it;

        return ans;
    }
};