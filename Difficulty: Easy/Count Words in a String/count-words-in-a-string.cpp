class Solution {
  public:
    int countWords(string &s) {
        // code here
        int ans = 0;
        
        stringstream ss(s);
        string a;
        while(ss>>a){
            ans++;
        }
        return ans;
    }
};