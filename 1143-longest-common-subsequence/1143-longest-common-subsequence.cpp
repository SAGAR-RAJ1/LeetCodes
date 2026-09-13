class Solution {
public:
    vector<vector<int>>dp;
    int solve(string& text1, string& text2 , int i , int j){

        if(i<0 ||j<0)return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j]=1+solve(text1,text2,i-1,j-1);
        }else{
            return dp[i][j]=max(solve(text1,text2,i-1,j),solve(text1,text2,i,j-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        dp.assign(n1,vector<int>(n2,-1));
        return solve(text1,text2,n1-1,n2-1);
    }
};