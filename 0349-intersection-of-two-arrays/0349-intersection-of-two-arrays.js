/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let s = new Set();

    for(const a of nums1){
        s.add(a);
    }

    let ans = [];

    for(const a of nums2){
        if(s.has(a)){
            ans.push(a);
            s.delete(a);
        }
    }
    return ans;
};