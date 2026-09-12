class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>last(3,-1);
        int right = 0;
        int ans=0;
        int n = s.size();

        while(right<n){

            last[s[right]-'a']=right;

            if(last[0]>=0 && last[1]>=0 && last[2]>=0){
               ans+=1+min({last[0],last[1],last[2]});
            }
           right++;

        }
        return ans;
    }
};