class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int start=-1;
        int n = arr.size();
        
        for(int i = 0 ; i<n;i++){
            if(arr[i]==0){
                start=i;
                break;
            }
        }
        if(start==-1)return;
        
        for(int i = start+1;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i],arr[start]);
                start++;
            }
        }
    }
};