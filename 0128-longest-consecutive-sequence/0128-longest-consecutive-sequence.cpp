class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto &a : nums){
            s.insert(a);
        }
        if(nums.size()==0)return 0;
        int maxl=1;
        for(auto &it:s){
            if(s.find(it-1)==s.end()){
               int curr=1;
               int x=it;

               while(s.find(x+1)!=s.end()){
                curr++;
                x++;
               }
               maxl=max(maxl,curr);
            }
        }
        return maxl;
    }
};