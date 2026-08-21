class Solution {
  public:

    int transform(string &s1, string &s2) {
        // code here
        int m = s1.size();
        int n = s2.size();
        
        if(m!=n)return -1;
        
        string a = s1;
        string b = s2;
        sort(a.begin(),a.end());sort(b.begin(),b.end());
        
        for(int i = 0 ; i< m ; i++ ){
            if(a[i]!=b[i])return -1;
        }
        
        int i = m-1;int j = n-1;
        while(i>=0){
            
            if(s1[i]==s2[j]){
                i--;j--;
            }else{
                i--;
            }
        }
       
       
        
        
        
        return j+1;
        
    }
};
