class Solution:
    def areAnagrams(self, s1, s2):
       # code here

       n1 = len(s1)
       n2 = len(s2)
       freq = {}
       for i in s1:
           freq[i] = freq.get(i, 0) + 1
       for j in s2:
           if j not in freq:
               return False
           else:
               freq[j]-=1
               if freq[j]<0:
                   return False
       return True
           

