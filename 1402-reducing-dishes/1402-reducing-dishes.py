class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        satisfaction.reverse()
        while sum(satisfaction)<0:
            satisfaction.pop()
        s=0
        l=len(satisfaction)
        for i in range(l):
            s=s+satisfaction[i]*(l-i)
        return s
