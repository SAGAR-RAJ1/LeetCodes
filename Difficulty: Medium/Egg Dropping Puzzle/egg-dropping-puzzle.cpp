class Solution {
  public:
   vector<vector<int>>dp;
    int solve(int e, int f){
        
        if(f==0 || f==1)return f;
        if(e==1)return f;
        
        int ans = INT_MAX;
        if(dp[e][f]!=-1)return dp[e][f];
        int i = 1 ; int j = f;
        while(i<=j){
            
            int mid = i+(j-i)/2;
            
            int breaks = solve(e-1,mid-1);
            int nobreaks = solve(e,f-mid);
            int temp = 1 + max(breaks,nobreaks);
            
            if(breaks>nobreaks){
                j=mid-1;
            }else{
                i=mid+1;
            }
            
            ans=min(ans,temp);
        }
        
        return dp[e][f]=ans;
        
    }
    int eggDrop(int n, int k) {
        // code here
        dp.assign(n+1,vector<int>(k+1,-1));
        
        return solve(n,k);
        
    }
};