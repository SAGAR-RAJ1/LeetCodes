class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int smallest = INT_MAX;
        int j = -1;
        int count=1;
        for (int i = 0; i < n; i++) {
           if(s[i]=='1'){
            j=i;break;
           }
        }
        if(j==-1)return "";
        if(k==1)return "1";

        for (int i = j+1; i < n; i++) {
           if(s[i]=='1')count++;

           if(count==k){
            string curr = s.substr(j,i-j+1);
            if((i-j+1)<smallest){
                ans = curr;
                smallest=i-j+1;
            }else if((i-j+1)==smallest && curr<ans){
                 ans=curr;
            }
            j=j+1;count--;
            while(j<n && s[j]=='0'){
                j++;
            }

           }
        }
        return ans;
    }
};