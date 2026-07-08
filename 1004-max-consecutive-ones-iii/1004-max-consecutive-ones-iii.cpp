class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //we can change the question to atmost k zeroes;

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