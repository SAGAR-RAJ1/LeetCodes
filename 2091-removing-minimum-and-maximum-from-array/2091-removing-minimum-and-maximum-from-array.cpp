class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 1;
        int minindex = min_element(nums.begin(),nums.end())-nums.begin();
        int maxindex = max_element(nums.begin(),nums.end())-nums.begin();
         
        int ans = INT_MAX;
        
        //if all from left 
        ans=min(ans,max(minindex,maxindex)+1);
        //if all from right 
        ans=min(ans,n-min(minindex,maxindex));
        //if all from both 
        int nearleft = 1+min(minindex,maxindex);
        int nearright =n-max(minindex,maxindex);
        ans=min(ans,nearleft+nearright);

        return ans;

    }
};