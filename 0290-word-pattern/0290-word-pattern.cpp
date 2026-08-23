class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>m;
        unordered_set<string> used;
        int i = 0;
        stringstream ss(s);
        string a;
        while(ss>>a){

            if(i>=pattern.size())return false;

            if(m.find(pattern[i])!=m.end()){
                if(m[pattern[i]]!=a)return false;

            }else{
                if(used.find(a)!=used.end())return false;
                m[pattern[i]]=a;
                used.insert(a);
            }
            i++;
        }
        
        if(i<pattern.size())return false;
        return true;;
    }
};