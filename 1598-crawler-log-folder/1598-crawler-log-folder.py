class Solution:
    def minOperations(self, logs: List[str]) -> int:
        cntr=0
        for x in logs:
            if x[0]=='.' and x[1]=='.':
                if cntr>0:
                    cntr=cntr-1
            elif x[0]=='.' and x[1]=='/':
                continue;
            else:
                cntr=cntr+1
                
        return cntr