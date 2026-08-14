class Solution {
  public:
    vector<vector<int>>dp;
    bool solve(vector<int>& arr,int index, int sum){
        
        if(sum==0)return true;
        if(index==0){
            return arr[index]==sum;
        }
        if(dp[index][sum]!=-1)return dp[index][sum];
        bool nottake = solve(arr,index-1,sum);
        bool take =false;
        if(arr[index]<=sum)take = solve(arr,index-1,sum-arr[index]);
        
        return dp[index][sum]=take||nottake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        //index , sum
        dp.assign(201,vector<int>(1e4+1,-1));
        return solve(arr,n-1,sum);
    }
};