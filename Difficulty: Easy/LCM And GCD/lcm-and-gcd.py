class Solution:
    def lcmAndGcd(self, a : int, b : int) -> List[int]:
        # code here
        gc = math.gcd(a,b)
        lc=(a*b)//gc
        return [lc,gc]