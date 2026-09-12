class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;

        int left=0;
        int right=0;
        int ans = 0;
        int n = s.size();

        while(right<n){
            m[s[right]]++;

            if(m[s[right]]>1){
                while(m[s[right]]>1){
                        m[s[left]]--;left++;
                }
            }

            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};