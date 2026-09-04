class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxi(n);
        vector<int>mini(n);
         int maxim = INT_MIN;
        for(int i = 0 ; i<n;i++){
            maxim=max(maxim,nums[i]);
            maxi[i]=maxim;
        }
         int minim = INT_MAX;
        for(int i = n-1 ; i>=0;i--){
            minim=min(minim,nums[i]);
            mini[i]=minim;
        }
        
        for(int i = 0 ; i<n;i++){
            if((maxi[i]-mini[i])<=k)return i;
        }

        return -1;
    }
};