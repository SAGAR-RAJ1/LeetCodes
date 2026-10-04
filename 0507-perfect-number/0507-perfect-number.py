class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        check=1
        if num==1:
            return False
        end=int(sqrt(num))+1
        for i in range(2,end):
            if num%i==0:
                check+=i
                if i!=num//i:
                    check+=num//i
        if num==check:
            return True
        return False

        