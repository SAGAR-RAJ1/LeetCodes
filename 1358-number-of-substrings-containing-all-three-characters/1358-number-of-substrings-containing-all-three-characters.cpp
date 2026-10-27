class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>last={-1,-1,-1};
        int ans = 0;
        int r = 0;
        int n = s.size();
        while(r<n){
            last[s[r]-'a']=r;

            ans+=1+min({last[0],last[1],last[2]});
            r++;
        }
        return ans;
    }
};