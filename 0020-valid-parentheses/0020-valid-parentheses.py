class Solution:
    def isValid(self, s: str) -> bool:
        q=deque()
        n=len(s)
        for ch in s:
            if ch=='(' or ch=='[' or ch=='{' :
                q.append(ch)
            else:
                if len(q)==0:
                    return False
                
                if q[-1]=='(' and ch==')' :
                    q.pop()
                elif q[-1]=='[' and ch==']' :
                    q.pop()
                elif q[-1]=='{' and ch=='}' :
                    q.pop()
                else:
                    return False
        if len(q)!=0:
            return False
        return True