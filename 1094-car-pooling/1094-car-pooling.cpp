class Solution {
public:
    static bool comporator(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

        sort(trips.begin(),trips.end(),comporator);
        
        for(auto &a:trips){
           int number = a[0];
           int start = a[1];
           int end = a[2];

           while(!q.empty() && q.top().first<=start){
             capacity+=q.top().second;
             q.pop();
           }
            capacity-=number;
           if(capacity<0)return false;
           q.push({end,number});
           
        }

        return true;
    }
};