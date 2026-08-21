class Solution {
public:
    vector<long long>dp;
    int getidx(vector<vector<int>>& rides,int end){

        int s = 0 ;
        int e = rides.size()-1;
        int ans=e+1;
        while(s<=e){
            int mid = s+(e-s)/2;

            if(rides[mid][0]<end){
               
               s=mid+1;
            }else{
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
    long long solve(vector<vector<int>>& rides,int row){
        if(row>=rides.size())return 0;
        if(dp[row]!=-1)return dp[row];
        long long nottake = solve(rides,row+1);
        long long take = 0 ;

        int start = rides[row][0];
        int end = rides[row][1];
        int tip = rides[row][2];

        int profit = end-start+tip;

        int nextidx = getidx(rides,end);
        take = profit + solve(rides,nextidx);
        return dp[row]=max(take,nottake);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        int m = rides.size();
        dp.assign(m+1,-1);
        sort(rides.begin(),rides.end());

        return solve(rides,0);


    }
};