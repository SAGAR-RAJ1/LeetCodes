class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> s;
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {

            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = s.top();
            }
            s.push(nums2[i]);
        }
vector<int>res;
        for(int i = 0 ; i<m;i++){
            for(int j = 0 ; j<n;j++){
                if(nums1[i]==nums2[j]){
                    res.push_back(ans[j]);
                }
            }
        }
        return res;
    }
};