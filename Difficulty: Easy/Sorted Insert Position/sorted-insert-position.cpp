// User function Template for C++

class Solution {
  public:
    int searchInsertK(vector<int> Arr ,int k) {
        
        // code here
        
        int lb = lower_bound(Arr.begin(),Arr.end(),k)-Arr.begin();
        
        return lb;
    }
};