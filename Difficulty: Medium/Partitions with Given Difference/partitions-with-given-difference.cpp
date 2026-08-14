class Solution {
  public:
   vector<vector<int>>dp;
    int solve(vector<int>& arr, int target , int i ){
        
        if(i<0){
            if(target==0)return 1;
            return 0;
        }
        if(dp[i][target]!= -1)return dp[i][target];
        int notpick = solve(arr,target,i-1);
        int pick = 0;
        if(arr[i]<=target)pick = solve(arr,target-arr[i],i-1);
        
        return dp[i][target]=pick+notpick;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int sum = 0;
        int n = arr.size();
        for(auto &a:arr)sum+=a;
        
        if(sum<diff || (sum+diff)%2!=0 )return 0;
        int target = (sum+diff)/2;
        dp.assign(n,vector<int>(target+1,-1));
        return solve(arr,target,n-1);
        
    }
};