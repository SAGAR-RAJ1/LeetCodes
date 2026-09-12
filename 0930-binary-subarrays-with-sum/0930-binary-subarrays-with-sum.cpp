class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>m;
        m[0]=1;
        int ans=0;
        int sum=0;
        for(auto &a:nums){
            sum+=a;
            int rem=sum-goal;
            if(m.find(rem)!=m.end()){
               ans+=m[rem];
            }

            m[sum]++;
        }
        return ans;
    }
};