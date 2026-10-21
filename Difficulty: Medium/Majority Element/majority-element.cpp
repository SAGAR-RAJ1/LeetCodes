class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int el = -1;
        int count=0;
        int n = arr.size();
        
        for(int i = 0 ; i<n; i++){
            if(count==0 || arr[i]==el){
                count++;
                el=arr[i];
            }else{
                count--;
            }
        }
        
        int freq=0;
        for(int i = 0 ; i<n; i++){
            if(arr[i]==el)freq++;
        }
        
        if(freq>n/2)return el;
        return -1;
    }
};