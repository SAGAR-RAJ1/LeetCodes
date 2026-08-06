class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int maxi = 0;
        int sum = 0;
        int start=0,ansstart=0,end=-1;
        
        for(int i = 0; i<n;i++){
            sum+=arr[i];
            if(arr[i]<0){
                sum=0;start=i+1;
            }else{
                if(sum>maxi || (sum == maxi && (i - start > end - ansstart))){
                    maxi=sum;
                    ansstart=start;
                    end=i;
                }
            }
            
        }
        if(maxi==0)return {-1};
        vector<int>ans;
        
        for(int i = ansstart;i<=end;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};