class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
              // index  element
        deque<pair<int,int>>dq;
        
        for(int i = 0 ; i< n ; i++){

            if(!dq.empty() && dq.front().first<=i-k)dq.pop_front();

            while(!dq.empty() && dq.back().second<=nums[i] )dq.pop_back();

            dq.push_back({i,nums[i]});

            if(i>=k-1)ans.push_back(dq.front().second);
        }

       return ans;
    }
};