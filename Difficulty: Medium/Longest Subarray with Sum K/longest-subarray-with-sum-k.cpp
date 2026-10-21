class Solution {
	public:
	int longestSubarray(vector<int>& arr, int k) {
		// code here
		int n = arr.size();
		int sum = 0;
		int ans = 0;
		unordered_map<long long, int>m;
		
		for (int i = 0 ; i<n; i++) {
			sum += arr[i];
			
			if (sum == k) {
				ans = max(ans, i + 1);
			}
			
			int rem = sum-k;
			if (m.find(rem) != m.end()) {
				ans = max(ans, i - m[rem]);
			}
			if (m.find(sum) == m.end()) {
				m[sum]=i;
			}
		}
		
		return ans;
	}
};
