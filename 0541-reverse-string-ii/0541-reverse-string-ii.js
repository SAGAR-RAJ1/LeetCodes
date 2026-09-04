/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function(s, k) {
    
    let n = s.length;
    if(k==1)return s;
    if(n<=k){
        return s.split('').reverse().join("");
    }
    let temp = s.split("");
    for(let i = 0 ; i<n ; i=i+2*k ){
         
         let left = i;
         let right = Math.min(i+k-1,n-1);

         while(left<right){
            [temp[left],temp[right]]=[temp[right],temp[left]];
            left++;right--;
         }
    }

    return temp.join("");
};