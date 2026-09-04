/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    
    let m = new Map();

    for(const ch of magazine){
        m.set(ch,(m.get(ch)||0)+1);
    }

    for(const ch of ransomNote){

        if(m.has(ch)){
             m.set(ch,m.get(ch)-1);
             if(m.get(ch)==0)m.delete(ch);
        }else{
            return false;
        }
    }

    return true;
};