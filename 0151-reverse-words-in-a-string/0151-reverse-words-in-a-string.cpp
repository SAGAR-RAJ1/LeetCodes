class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);

        vector<string>temp;
        string a;
        while(ss>>a){
            temp.push_back(a);
        }
        reverse(temp.begin(),temp.end());
        string ans="";
        for(int i = 0 ; i<temp.size();i++){

            if(i>0)ans+=" ";
            ans+=temp[i];
        }

        return ans;
    }
};