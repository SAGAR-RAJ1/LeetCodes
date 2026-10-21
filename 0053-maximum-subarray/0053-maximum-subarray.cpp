class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0 ;
        int sum = 0;
        int ans = INT_MIN;
        int n =nums.size();
        for(int i = 0 ; i<n; i++){
             sum+=nums[i];
             ans=max(ans,sum);
              while(l<=i && sum<0){
                sum-=nums[l];l++;
              }
             
        }
        return ans;
    }
};