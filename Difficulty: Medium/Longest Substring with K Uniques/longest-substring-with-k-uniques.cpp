class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int left=0;
        int right = 0;
        int ans=-1;
        int n = s.size();
        unordered_map<char,int>m;
        
        while(right<n){
            
            m[s[right]]++;
            
            while(m.size()>k){
                m[s[left]]--;
                if(m[s[left]]==0)m.erase(s[left]);
                left++;
            }
            
            if(m.size()==k)ans=max(ans,right-left+1);
            right++;
        }
        
        return ans;
    }
};