class Solution {
  public:
    vector<vector<int>>dp;
    int solve(vector<int>& h, vector<int>& l,int i ,int lastday) {
        // code here
        //base case
        if(i==h.size()-1){
            
            if(lastday==0 || lastday==2){
                return max(l[i],h[i]);
            }
            
            return l[i];
        }
        if(dp[i][lastday]!=-1)return dp[i][lastday];
        //all operations
        // int high = 0;
        if(lastday==0 || lastday==2){//notperfomed and first day
             int high =h[i]+ solve(h,l,i+1,1);
             int low =l[i] + solve(h,l,i+1,1);
             int notask = solve(h,l,i+1,0);
             
             return dp[i][lastday]=max({high,low,notask});
        }else{
             int low =l[i] + solve(h,l,i+1,1);
             int notask = solve(h,l,i+1,0);
             
             return dp[i][lastday]=max(low,notask);
        }
        
    }
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n = h.size();
        dp.assign(n,vector<int>(3,-1));
        
        return solve(h,l,0,2);
    }
};