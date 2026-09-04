/**
 * @param {string} jewels
 * @param {string} stones
 * @return {number}
 */
var numJewelsInStones = function(jewels, stones) {
    
    let s = new Set();

    for(const ch of jewels){
        s.add(ch);
    }
    let count=0;
    for(const ch of stones){
        if(s.has(ch))count++;
    }

    return count;

};