class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n = s.size();
        int r=0,l=0,maxfreq=0,ans=0;
        int freq[26]={0};
        while(r<n){
            freq[s[r]-'A']++;
            
            maxfreq=max(maxfreq,freq[s[r]-'A']);
            
            while((r-l+1)-maxfreq>k){
                freq[s[l]-'A']--;l++;
            }
            
            if((r-l+1)-maxfreq<=k)ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};