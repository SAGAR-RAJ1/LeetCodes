class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>res;
        int n = nums.size();
        if(n<4)return {};
        for(int i = 0 ; i< n ; i++){
            for(int j=i+1 ; j< n ; j++){
            int l = n-1;
            int k = j+1;
        
               while(l>k){
          long long sum = (long long)nums[i]+nums[j]+nums[k]+nums[l];

                 if(sum<target){
                   k++;
                 }else if(sum>target){
                   l--;
                 }else{
                  vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                  res.insert(temp);
                  while(k<l && nums[k]==nums[k+1])k++;
                  while(k<l && nums[l]==nums[l-1])l--;
                  k++,l--;
                 }
               }
            } 
         }
     vector<vector<int>>ans(res.begin(),res.end());
     return ans;
    }
};