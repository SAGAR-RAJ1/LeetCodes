class Solution {
public:
     vector<vector<int>>dp;
     int solve(string & word1, string & word2, int i, int j) {

        // base case

        if (i < 0) {
            return j + 1;
        }
        if (j < 0) {
            return i + 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // operations

        if (word1[i] == word2[j]) {
            return dp[i][j]=solve(word1, word2, i - 1, j - 1);
        } else {
            return dp[i][j]=1 + min({solve(word1, word2, i - 1, j - 1), // replace
                            solve(word1, word2, i, j - 1),     // insert
                            solve(word1, word2, i - 1, j)});   // delete
        }
    }
    int minDistance(string& word1, string& word2) {

        int m = word1.size();
        int n = word2.size();
        dp.assign(m,vector<int>(n,-1));

        return solve(word1, word2, m - 1, n - 1);
    }
};