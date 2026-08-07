class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        long ans=0;
        int xr = 0 ;
        unordered_map<int,int>m;
        m[0]++;
        for(int i = 0 ; i< n ; i++){
            
            xr^=arr[i];
            int find = xr^k;
            if(m.find(find)!=m.end()){
                ans+=m[find];
            }
            
            m[xr]++;
        }
        
        return ans;
    }
};