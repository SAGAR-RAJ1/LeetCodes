class Solution {
  public:
    bool match(string pat, string word) {
        unordered_map<char, char> mp;
        unordered_set<char> used;
        
        if(pat.size()!=word.size())return false;
        
        for(int i = 0 ; i<pat.size() ; i++){
            
            if(mp.find(pat[i])!=mp.end()){
                if (mp[pat[i]] != word[i])
                return false;
            }else{
                
                if(used.find(word[i]) != used.end()){
                    return false;
                }
                
                used.insert(word[i]);
                mp[pat[i]]=word[i];
            }
        }
        
        return true;

        
    }
    vector<string> matchingStrings(vector<string>& d, string& pat) {
        // code here
        
        vector<string>ans;
        for(auto &a:d){
            if(match(pat,a))ans.push_back(a);
        }
        return ans;
    }
};