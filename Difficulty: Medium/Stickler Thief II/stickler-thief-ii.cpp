class Solution {
  public:
    vector<int>dp;
    int help(vector<int>& arr,int i){
        if(i==0)return arr[i];
        if(i<0)return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        int take = arr[i]+help(arr,i-2);
        int nottake = 0+help(arr,i-1);
        
        return dp[i]=max(take,nottake);
    }
    int maxValue(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n==1)return arr[0];
        dp.assign(n,-1);
        
        vector<int>num;
        for(int i = 1 ; i<n;i++){
            num.push_back(arr[i]);
        }
        
        int temp1 = help(arr,n-2);
         dp.assign(n,-1);
        int temp2 = help(num,n-2);
        
        return max(temp1,temp2);
        
        
    }
};
