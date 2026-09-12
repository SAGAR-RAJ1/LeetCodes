class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int>count(2,0);
        int ans=0;
        int n = nums.size();
        int left=0;
        int right=0;

        while(right<n){

            count[nums[right]]++;

            while(count[0]>k){
                   count[nums[left]]--;
                   left++;
            }

            ans=max(ans,right-left+1);
            right++;
        }

        return ans;
    }
};