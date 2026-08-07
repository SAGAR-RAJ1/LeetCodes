class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>count(n*n,0);
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j<n;j++){
                 count[grid[i][j]-1]++;
            }
        }
         int r, m ;
        for(int i = 0 ; i<n*n;i++){
             if(count[i]==0)m=i+1;
             if(count[i]>1)r=i+1;
        }

        return {r,m};
    }
};