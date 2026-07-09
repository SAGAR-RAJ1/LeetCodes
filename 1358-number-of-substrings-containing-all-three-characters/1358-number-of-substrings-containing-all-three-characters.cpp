class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        int lastseen[3] = {-1,-1,-1};

        for(int i = 0; i< n ; i++){
           lastseen[s[i]-'a']=i;

           ans+=1+min({lastseen[0],lastseen[1],lastseen[2]});
        }
        return ans; 
    }
};