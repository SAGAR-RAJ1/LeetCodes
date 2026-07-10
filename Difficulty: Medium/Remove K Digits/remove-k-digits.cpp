class Solution {
  public:
    string removeKdig(string &st, int k) {
        // code here
        int n = st.size();
        stack<char>s;
        
        for(int i = 0 ; i< n ; i++){
            
            while(!s.empty() && s.top()>st[i] && k>0)s.pop(),k--;
            
            s.push(st[i]);
        }
        //if k is remaining
        while(!s.empty() && k>0)s.pop(),k--;
        
        string ans = "";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        for( ; i<ans.size();i++){
            if(ans[i]!='0')break;
        }
        
        ans=ans.substr(i);
        
        if(ans.size()==0)return "0";
        
        return ans;
    }
};