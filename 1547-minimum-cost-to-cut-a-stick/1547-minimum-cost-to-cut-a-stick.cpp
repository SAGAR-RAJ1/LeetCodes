class Solution {
public:
    vector<vector<int>>dp;
    long long solve(vector<int>& cuts,int i , int j){

        if(i>j)return 0;

        long long mini = INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k = i ; k<=j;k++){
            
            long long cost = (cuts[j+1]-cuts[i-1])+solve(cuts,i,k-1)+solve(cuts,k+1,j);

            mini=min(mini,cost);
        }

        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        dp.assign(m+3,vector<int>(m+3,-1));
        return solve(cuts,1,m);
    }
};