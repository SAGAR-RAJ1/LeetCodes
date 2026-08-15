class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        int tsize = m + n;
        string ans = "";

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        // for (int i = 0; i <= m; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << " " << dp[i][j] << "        ";
        //     }
        //     cout << endl;
        // }

        int i = m;
        int j = n;

        while(i>0 && j>0){

            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;j--;
            }else if(dp[i][j-1]>dp[i-1][j]){
                ans+=s2[j-1];
                j--;
            }else{
                ans+=s1[i-1];
                i--;
            }
        }
         while(i>0){
             ans+=s1[i-1];
                i--;
         }
         while(j>0){
             ans+=s2[j-1];
                j--;
         }
         reverse(ans.begin(),ans.end());
        return ans;
    }
};