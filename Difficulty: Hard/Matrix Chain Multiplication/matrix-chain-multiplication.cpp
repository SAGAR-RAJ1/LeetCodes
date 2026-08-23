class Solution {
  public:
    vector<vector<int>>dp;
    int solve(vector<int> &arr,int i , int j){
        
        if(i>=j)return 0;
        int ans = INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k = i ; k<j;k++){
            
            int l = solve(arr,i,k);
            int r = solve(arr,k+1,j);
            int curr = arr[i-1]*arr[k]*arr[j];
            ans = min(ans,l+r+curr);
        }
        
        return dp[i][j]=ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(arr,1,n-1);
    }
};