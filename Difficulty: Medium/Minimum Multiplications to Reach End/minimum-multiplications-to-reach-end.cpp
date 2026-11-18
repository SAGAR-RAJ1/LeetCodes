// User function Template for C++

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        vector<int>dist(1000,INT_MAX);
           if (start == end) return 0;            

        const int MOD = 1000;
        queue<pair<int,int>>q;
        q.push({start,0});
        
         dist[start]=0;
         
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            
            int node = a.first;
            int step = a.second;
            
            for(auto & i : arr){
                
                int number = (i*node)%1000;
                if(step+1<dist[number]){
                    dist[number]=step+1;
                    q.push({number,step+1});
                    
                    if(number==end)return step+1;
                
            }
            }
        }
        return -1;
    }
};
