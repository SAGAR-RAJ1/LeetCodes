class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(string& s1, string& s2, int i, int j) {

    //     if (i < 0 || j < 0)
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (s1[i] == s2[j]) {
    //         return dp[i][j] = solve(s1, s2, i - 1, j - 1) + 1;
    //     } else {
    //         return dp[i][j] =
    //                    max(solve(s1, s2, i, j - 1), solve(s1, s2, i - 1, j));
    //     }
    // }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }
};