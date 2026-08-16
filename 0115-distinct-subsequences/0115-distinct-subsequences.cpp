class Solution {
public: 
    vector<vector<int>>dp;
    int solve(string & s, string & t,int i , int j){

        ///base case
         if(j<0)return 1;
         if(i<0)return 0;
         if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=solve(s,t,i-1,j-1)+solve(s,t,i-1,j);
        }else{
            return dp[i][j]=solve(s,t,i-1,j);
        }
    }
    int numDistinct(string & s, string & t) {
         int m = s.size();
         int n = t.size();
         dp.assign(m,vector<int>(n,-1));

         return solve(s,t,m-1,n-1);
    }
};