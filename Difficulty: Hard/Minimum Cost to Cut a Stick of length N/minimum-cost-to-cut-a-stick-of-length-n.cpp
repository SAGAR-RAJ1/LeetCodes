class Solution {
  public:
    vector<vector<int>>dp;
    int solve(vector<int>& cuts,int i , int j){
        
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = INT_MAX;
        for(int k = i ; k<=j ; k++){
            int temp = (cuts[j+1]-cuts[i-1])+solve(cuts,k+1,j)+solve(cuts,i,k-1);
            mini = min(mini,temp);
        }
        
        return dp[i][j]=mini;
        
    }
    int minCutCost(int n, vector<int>& cuts) {
        // code here
        
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        dp.assign(m+3,vector<int>(m+3,-1));
        
        return solve(cuts,1,m);
        
        
    }
};