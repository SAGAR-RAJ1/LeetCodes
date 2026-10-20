class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        for(int i = 1; i<n;i++){
            if(nums[start]!=nums[i]){
                swap(nums[i],nums[start+1]);
                start++;
            }
        }
        return start+1;
    }
};