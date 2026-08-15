class Solution {
  public:
    vector<vector<int>>dp;
    int solve(vector<int>&price ,int i , int length){
        
        if(i<0){
            return 0;
        }
        if(dp[i][length]!=-1)return dp[i][length];
        
        int notcut = solve(price,i-1,length);
        int cut = INT_MIN;
        if(length>=(i+1))cut = price[i]+ solve(price,i,length-i-1);
        
        return dp[i][length]=max(cut,notcut);    
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        dp.assign(n,vector<int>(n+1,-1));
        
        return solve(price,n-1,n);
        
    }
};