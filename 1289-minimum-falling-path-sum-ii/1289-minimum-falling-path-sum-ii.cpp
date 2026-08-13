class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& matrix, int m, int n) {
        int ml = matrix.size();
        int nl = matrix[0].size();
        if (m == ml - 1)
            return matrix[m][n];
        if (dp[m][n] != INT_MAX)
            return dp[m][n];
        int mini = INT_MAX;
        for (int i = 0; i < nl; i++) {
            if (i != n) {
                int temp = matrix[m][n] + solve(matrix, m + 1, i);
                mini = min(temp, mini);
            }
        }

        return dp[m][n] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ml = matrix.size();

        int nl = matrix[0].size();

        dp.assign(ml, vector<int>(nl, INT_MAX));

        int ans = INT_MAX;

        for (int i = 0; i < nl; i++) {

            int temp = solve(matrix, 0, i);

            ans = min(ans, temp);
        }

        return ans;
    }
};