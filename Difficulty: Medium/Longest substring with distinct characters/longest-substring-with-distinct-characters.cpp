class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char,int>m;
        
        
        int first = 0 ; int second = 0 ; int length = 0;
        
        while(second<s.size()){
            
            m[s[second]]++;
            
            if(m[s[second]]>1){
                
                while(m[s[second]]>1){
                    m[s[first]]=0;
                    first++;
                }
                
                m[s[second]]=1;
            }
            
                
                length=max(length,second-first+1);
                second++;
        }
        
        return length;
        
        
    }
};
