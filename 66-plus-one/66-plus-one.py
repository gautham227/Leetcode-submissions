class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        s=""
        for i in digits:
            s=s+str(i)
        a=int(s)+1
        s=str(a)
        l=list(s)
        return l