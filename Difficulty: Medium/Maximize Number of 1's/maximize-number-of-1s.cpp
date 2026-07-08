class Solution {
  public:
    int maxOnes(vector<int>& nums, int k) {
        // code here
        vector<int>count(2,0);

        int first = 0 , second=0,length = 0;

        while(second<nums.size()){

            count[nums[second]]++;
            if(count[0]>k){
                while(count[0]>k){
                    count[nums[first]]--;
                    first++;
                }
            }
            length=max(length,second-first+1);
            second++;
        }
        return length;
    }
};
