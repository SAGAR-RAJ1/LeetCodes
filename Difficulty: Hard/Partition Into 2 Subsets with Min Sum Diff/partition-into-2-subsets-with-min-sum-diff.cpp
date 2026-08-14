class Solution {
public:
      vector<vector<int>>dp;
    bool solve(vector<int>& arr, int sum,int i){
        
        if(sum==0)return true;
        if(i<0)return false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool ans = false;
        if(arr[i]>sum){
            ans = solve(arr,sum,i-1);
        }else{
            ans=solve(arr,sum,i-1)||solve(arr,sum-arr[i],i-1);
        }
        
        return dp[i][sum]= ans;
    }

    int minDifference(vector<int>& nums) {
        int n = nums.size();
         int sum = 0;
         for(auto &a:nums){
            sum+=a;
         }
         dp.assign(n,vector<int>(sum+1,-1));
         int ans = INT_MAX;

         for(int i = sum/2 ; i>=0;i--){
            if(solve(nums,i,n-1)){
              ans=min(ans,abs(sum-2*i));
              break;
            }
         }

         return ans;
        
    }
};