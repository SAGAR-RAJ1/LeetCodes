class Solution {
	public:
	vector<vector<int>> dp;
	int help(vector<vector<int>> & mat, int row, int last) {
		
		if (row == 0) {
			int maxi = -1;
			for (int i = 0 ; i<3 ; i++) {
				if (i != last) {
					int temp = mat[row][i];
					maxi = max(maxi, temp);
				}
			}
			return maxi;
		}
		if(dp[row][last]!=-1)return dp[row][last]; 
		
		int maxi = -1;
		for (int i = 0 ; i<3 ; i++) {
			if (i != last) {
				int temp = mat[row][i]+help(mat, row - 1, i);
				maxi = max(maxi, temp);
			}
		}
		
		return dp[row][last]=maxi;
	}
	int maximumPoints(vector<vector<int>> & mat) {
		// code here
	
		int n = mat.size();
			dp.assign(n,vector<int>(4,-1));
		return help(mat,n-1,3);
		
	}
};
