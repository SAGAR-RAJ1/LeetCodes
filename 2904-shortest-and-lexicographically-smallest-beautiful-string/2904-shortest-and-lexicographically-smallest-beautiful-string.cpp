class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";

        set<string> st;
        int i = 0;
        int smallest=INT_MAX;
        for (int i = 0; i < n; i++) {
            int count=0;
            for (int j = i; j < n; j++) {
              if(s[j]=='1')count++;
              if(count==k && (j-i+1)<smallest){
                st.clear();
                st.insert(s.substr(i,j-i+1));
                smallest=j-i+1;
              }
              if(count==k && (j-i+1)==smallest){
                st.insert(s.substr(i,j-i+1));
              }
              if(count>k)break;
            }
        }
        if (st.empty())return "";
        return *st.begin();
    }
};