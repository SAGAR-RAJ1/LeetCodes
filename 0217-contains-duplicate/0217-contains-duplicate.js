/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let m = new Set();
    let n = nums.length;

    for(let i = 0 ; i<n; i++){

        if(m.has(nums[i]))return true;
         m.add(nums[i]);
    }

    return false;
};