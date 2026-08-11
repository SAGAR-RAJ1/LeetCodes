class Solution {
	public:
	vector<int>dp;
	int help(vector<int>&height, int index) {
		if(index<=0)return 0;
		if(dp[index]!=-1)return dp[index];
		int one = help(height, index - 1) + abs(height[index]-height[index - 1]);
		 int two = INT_MAX;
	 if(index>1)two = help(height, index - 2) + abs(height[index]-height[index - 2]);
		
		return dp[index]=min(one,two);
	}
	int minCost(vector<int>& height) {
		// Code here
		int n = height.size();
		dp.assign(n + 1, -1);
		
		return help(height, n - 1);
		
	}
};
