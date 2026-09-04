/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    let n= nums.length;
    let ans = new Array(n);
    let sum = 0;
    for(let i = 0 ; i<n ; i++){
       sum+=nums[i];
       ans[i]=sum;
    }
    return ans;
};