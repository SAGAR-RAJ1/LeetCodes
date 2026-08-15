class Solution {
public:
    vector<vector<int>>dp;
    int solve(string & s1, string & s2 , int i , int j){

        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(s1,s2,i-1,j-1)+1;
        }else{
            return dp[i][j]=max(solve(s1,s2,i,j-1),solve(s1,s2,i-1,j));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m = text2.size();
        dp.assign(n,vector<int>(m,-1));

        return solve(text1,text2,n-1,m-1);

    }
};