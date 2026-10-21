class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {

        int n = arr.size();
        int l = 0;
        int r = n - 1;
        // sort(arr.begin(), arr.end());
        while (l < r) {
            int sum = arr[l] + arr[r];
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                return {l+1, r+1};
            }
        }
        return {};
    }
}
;