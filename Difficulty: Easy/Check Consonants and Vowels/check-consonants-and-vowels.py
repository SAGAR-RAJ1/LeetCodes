class Solution:
    def checkString(self, s):
        
        # Initializing vowel count
        # and consonant count to 0
        v = 0
        c = 0
        
        for ch in s:
            if ch in "aeiou":
                v+=1
            else:
                c+=1
        
        if(v>c):
            print("Yes")
        elif v<c:
            print("No")
        else:
            print("Same")
        