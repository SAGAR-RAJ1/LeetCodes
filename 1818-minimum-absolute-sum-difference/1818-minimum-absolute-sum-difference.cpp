class Solution {
public: 
   int mod = 1e9+7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int ans;
        vector<int> sorted = nums1;
        sort(sorted.begin(), sorted.end());
        long long diff = 0;
        long long  maxreduction=0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            long long  currdiff=abs(nums1[i] - nums2[i]);
            diff += currdiff;
            //just greater or equal than nums2[i]
            auto lb = lower_bound(sorted.begin(),sorted.end(),nums2[i]);
            
           if(lb!=sorted.end()){
             long long  newdiff = abs(*lb-nums2[i]);
             maxreduction=max(maxreduction,currdiff-newdiff);
           }
           //just lower than nums2[i]
           if(lb!=sorted.begin()){
             long long  newdiff = abs(*prev(lb)-nums2[i]);
             maxreduction=max(maxreduction,currdiff-newdiff);
           }

        }
        ans = (diff-maxreduction)%mod;
        return ans;
    }
};