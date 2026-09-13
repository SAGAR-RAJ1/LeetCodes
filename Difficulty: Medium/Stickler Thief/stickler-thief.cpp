class Solution {
  public:
    vector<vector<int>>dp;
    int solve(vector<int>&arr,int i,bool can){
        //base
        if(i<0)return 0;
        //op
        if(dp[i][can]!=-1)return dp[i][can];
        int pick = INT_MIN;
        if(can){
        pick = arr[i]+solve(arr,i-1,false);
        }
        int notpick = 0 + solve(arr,i-1,true);
        
        return dp[i][can]=max(pick,notpick);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        dp.assign(n+1,vector<int>(2,-1));
        return solve(arr,n-1,true);
    }
};