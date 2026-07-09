class Solution {
  public:
   int help(vector<int>& nums, int goal) {
        if(goal<0)return 0;
        int r = 0,l=0,ans=0,sum=0;
        int n = nums.size();
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }  

            ans+=(r-l+1);
            r++;
        }

        return ans;
    }
    int countSubarrays(vector<int>& nums, int k) {
        // code here
          int n = nums.size();
        for(int i = 0 ; i<n;i++){
            if(nums[i]%2==0)nums[i]=0;
            else nums[i]=1;
        }
          int goal =k;
         return help(nums,goal)-help(nums,goal-1);
    }
};