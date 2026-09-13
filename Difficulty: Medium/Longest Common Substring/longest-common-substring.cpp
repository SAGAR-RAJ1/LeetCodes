class Solution {
	public:
	vector<vector<int>> dp;
	int ans = 0;
	int solve(string& text1, string& text2, int i, int j) {
		
		if (i<0 || j<0)return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		if (text1[i] == text2[j]) {
			dp[i][j] = 1 + solve(text1, text2, i - 1, j - 1);
			ans = max(ans, dp[i][j]);
			return dp[i][j];
		} else {
			return dp[i][j] = 0;
		}
	}
	int longCommSubstr(string& s1, string& s2) {
		// code here
		int m = s1.size();
		int n = s2.size();
		
		dp.assign(m + 1, vector<int>(n + 1, -1));
		for (int i = 0; i < m; i++) {
			
			for (int j = 0; j < n; j++) {
				
				solve(s1, s2, i, j);
				
			}
			
		}
		return ans;
		
	}
};
