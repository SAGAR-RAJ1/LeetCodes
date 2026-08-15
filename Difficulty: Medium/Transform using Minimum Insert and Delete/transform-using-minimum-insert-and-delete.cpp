class Solution {
  public:
    vector<vector<int>>dp;
    int solve(string &s1, string &s2,int i , int j){
        
        if(i<0 || j< 0 )return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]= 1 + solve(s1,s2,i-1,j-1);
        }else{
            return dp[i][j]=max(solve(s1,s2,i,j-1),solve(s1,s2,i-1,j));
        }
    }
    int minOperations(string &s1, string &s2) {
        // code here
        
        int m = s1.size();
        int n = s2.size();
        dp.assign(m,vector<int>(n,-1));
        int len = solve(s1,s2,m-1,n-1);
        
        return (m+n)-(2*len);
    }
};