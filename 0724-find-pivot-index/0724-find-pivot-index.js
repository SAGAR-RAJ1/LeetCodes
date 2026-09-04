/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
    let n = nums.length;  
    let sum = 0;
    for(let i = 0 ; i<n ; i++){
       sum+=nums[i];
    }
    let rightsum =sum;
    let leftsum=0;

     for(let i = 0 ; i<n ; i++){
       rightsum-=nums[i];
       if(leftsum==rightsum)return i;
       leftsum+=nums[i];
    }

    return -1;
    


};