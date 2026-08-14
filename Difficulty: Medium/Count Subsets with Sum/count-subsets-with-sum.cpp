class Solution {
  public:
   vector<vector<int>>dp;
    int solve(vector<int>& arr, int target , int i ){
       
        if(i<0){
            if( target ==0 )return 1;
            return 0;
        }
        
        if(dp[target][i]!=-1)return dp[target][i];
        
        int notpick = solve(arr,target,i-1);
        int pick = 0;
        if(arr[i]<=target)pick=solve(arr,target-arr[i],i-1);
        
        return dp[target][i]=pick+notpick;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        dp.assign(target+1,vector<int>(n,-1));
        return solve(arr,target,n-1);
    }
};