class Solution {
public:
int help(vector<int>& nums, int k) {
        if(k<0)return 0;
        int r = 0,l=0,ans=0;
        unordered_map<int,int>m;
        int n = nums.size();
        while(r<n){
            m[nums[r]]++;
           
           while(m.size()>k){
             m[nums[l]]--;
             if(m[nums[l]]==0)m.erase(nums[l]);l++;
           }

           if(m.size()<=k){
            ans+=(r-l+1);
           }
           r++;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};