/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let m = new Map();
    let n = nums.length;
    for(let i = 0 ; i<n;i++){
        let req = target - nums[i];

        if(m.has(req)){
            return [m.get(req),i];
        }else{
            m.set(nums[i],i);
        }

      
    }
      return [];
};