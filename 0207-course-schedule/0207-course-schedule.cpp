class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for (auto &pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // edge: pre[1] -> pre[0]
        }

        queue<int>q;

        vector<int>indegree(numCourses,0);

        for(int i = 0; i<numCourses;i++){

            for(auto &it : adj[i]){
                indegree[it]++;
            }

        }

        for(int i = 0 ; i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>topo;

        while(!q.empty()){
           auto node =q.front();
           q.pop();
           topo.push_back(node);
           for(auto &a:adj[node]){
            indegree[a]--;
            if(indegree[a]==0)q.push(a);
           }
        }
         
         if(topo.size()!=numCourses)return false;

         return true;
    }
};