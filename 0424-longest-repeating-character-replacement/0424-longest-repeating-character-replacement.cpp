class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq=0;
        int n = s.size();
        unordered_map<char,int>m;
        int right = 0 ;
        int left = 0;
        int ans = 0;

        while(right<n){
            m[s[right]]++;

            maxfreq=max(maxfreq,m[s[right]]);
            while((right-left+1)-maxfreq>k){
                m[s[left]]--;
                left++;
            }

            if((right-left+1)-maxfreq<=k)ans=max(ans,right-left+1);
            right++;
        }
        return ans;

    }
};