class Solution {
public:

     int helper(int n , vector<int>&nums,vector<int>&dp){
        if(n==0)return nums[0];
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];


        int left = nums[n] + helper(n-2,nums,dp);
        int right = 0 + helper(n-1,nums,dp);

        return dp[n]=max(left,right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n+1,-1);
        vector<int>d(n+1,-1);

        vector<int>num1,num2;

        for(int i = 0 ; i< n ; i++){
              if(i != 0)num1.push_back(nums[i]);
              if(i != n-1)num2.push_back(nums[i]);
        }

       int a = helper(n-2,num1,dp);
       int b = helper(n-2,num2,d);
       
       cout<<a<<b;

       return max(a,b);



    }
};