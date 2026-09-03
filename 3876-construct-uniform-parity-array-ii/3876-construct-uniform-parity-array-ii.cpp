class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size();
        int even = 0;
        int odd = 0;
        int mini = INT_MAX;
        for (auto& a : nums1) {

            mini = min(mini, a);
            if (a % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }

        if (even == 0 || odd == 0)
            return true;
        for (auto& a : nums1) {
            
            while(a%2!=1 && a>0){
                a-=mini;
            }

            if(a%2==0)return false;
        }

        return true;
    }
};