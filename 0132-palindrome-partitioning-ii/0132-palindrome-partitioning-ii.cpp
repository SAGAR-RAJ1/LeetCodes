class Solution {
public:
   vector<vector<int>>dp;
   vector<vector<int>>pal;
    bool ispal(string& s,int i , int j){
         int ori = i;
         int orj = j;
          if(pal[ori][orj]!=-1)return pal[ori][orj];
        while(i<=j){

            if(s[i]!=s[j])return pal[ori][orj]=false;
            i++;j--;
        }

        return pal[ori][orj]=true;
    }
    int solve(string& s,int i , int j){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(ispal(s,i,j))return 0;
        
        int ans = INT_MAX;
        for(int k = i ; k<j ; k++){
            // ONLY branch if the left part is a palindrome.
            // This prevents an explosion of useless recursive calls.
            if (ispal(s, i, k)) { 
                // We made 1 cut at k. The left is a palindrome, so just solve the right side.
                int temp = 1 + solve(s, k+1, j); 
                ans=min(ans,temp);
            }
        }

        return dp[i][j]=ans;
    }
    int minCut(string& s) {
        int n = s.size();
        dp.assign(n,vector<int>(n,-1));
        pal.assign(n,vector<int>(n,-1));
        return solve(s,0,n-1);
    }
};