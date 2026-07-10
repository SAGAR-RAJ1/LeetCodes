class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>s;
        int n = arr.size();

        for(int i = 0 ;i< n ; i++){

            if(arr[i]>0)s.push(arr[i]);
            else{
            while(!s.empty() && s.top()>0 && s.top()<abs(arr[i]))s.pop();
            if(!s.empty() && s.top()==abs(arr[i]))s.pop();
            else if(s.empty() || s.top()<0)s.push(arr[i]);
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};