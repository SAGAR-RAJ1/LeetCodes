class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char>s;
        int n = num.size();
        if(k==n)return "0";

        for(int i = 0 ; i<n ; i++){
            while(!s.empty() && k>0 && s.top()>num[i])s.pop(),k--;
            s.push(num[i]);
        }

        while(k>0 && !s.empty())k--,s.pop();
        
        string ans = "";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }

        reverse(ans.begin(),ans.end());

        int i = 0 ;
        for(; i<ans.size();i++){
            if(ans[i]!='0')break;
        }

        ans=ans.substr(i);
         
         if(ans.size()==0)return "0";
         return ans;


    }
};