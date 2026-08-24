class Solution {
public:
    vector<vector<int>>dp;
    int solve(int e , int f){
      
      if(e==1)return f;

      if(f==0 || f==1)return f;
      if(dp[e][f]!=-1)return dp[e][f];
       
       int ans = INT_MAX;
       int i =1 ; int j = f;

       while(i<=j){
        int mid = i + ( j - i)/2;

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
    int twoEggDrop(int n) {
        dp.assign(3,vector<int>(n+1,-1));
        return solve(2,n);
    }
};