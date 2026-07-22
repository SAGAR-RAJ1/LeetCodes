class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int>m;

        for(auto &a:nums){
            m[a]++;
        }
        int it=0;
        for(auto &a:m){
            int i = a.first;
            int j = a.second;
            int count=0;

            while(count<2 && count <j){
                nums[it]=i;
                it++;count++;
            }
            
        }

        return it;
    }
};