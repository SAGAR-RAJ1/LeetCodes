class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 1;
        int minindex = min_element(nums.begin(),nums.end())-nums.begin();
        int maxindex = max_element(nums.begin(),nums.end())-nums.begin();
         
        int ans = 0;
        
        vector<int>value;
        value.push_back(abs(maxindex-minindex));
        value.push_back(1+min(maxindex,minindex));
        value.push_back(n-max(maxindex,minindex));

        sort(value.begin(),value.end());

        ans=value[0]+value[1];

        

        return ans;

    }
};