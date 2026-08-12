class Solution {
  public:
   vector<int>dp;
   int help(vector<int>&arr,int i){
       
       if(i==0)return arr[0];
       if(i<0)return 0;
       if(dp[i]!=-1)return dp[i];
       
       int pick = arr[i]+help(arr,i-2);
       int nopick = 0 + help(arr,i-1);
       
       return dp[i]=max(pick,nopick);
   }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        dp.assign(n+1,-1);
        
        return help(arr,n-1);
    }
};