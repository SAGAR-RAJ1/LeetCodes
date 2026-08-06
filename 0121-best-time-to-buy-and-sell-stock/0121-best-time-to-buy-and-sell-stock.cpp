class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int buy = prices[0];
        for(int i = 1 ; i< n ; i++){
            int cost = prices[i]-buy;
            ans=max(ans,cost);
            buy = min(buy,prices[i]);

        }
        return ans;
    }
};