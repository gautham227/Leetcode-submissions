class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        d={}
        for i in nums:
            try:
                d[i]=d[i]+1
            except:
                d[i]=1
        s=0
        for i in d.values():
            s=s+(i*(i-1)/2)
        return int(s)