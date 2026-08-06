class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el  ;
        int n = nums.size();
        int count = 0;
        
        for(int i = 0 ; i< n ; i++){
           
           if(count == 0 ){
            el=nums[i];count++;
           }else if(el == nums[i]){
              count++;
           }else{
              count--;
           }
        }
        count=0;
        for(int i = 0 ; i< n ; i++){
          if(el==nums[i])count++;
        }

        if(count>(n/2))return el;
        return -1;
    }
};