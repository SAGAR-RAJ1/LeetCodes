class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;
        for(auto &A: nums)s.insert(A);
        int multiple=k;
        while(true){
           
           if(s.find(multiple)==s.end()){
            return multiple;
           }

           multiple+=k;
        }

        return -1;
    }
};