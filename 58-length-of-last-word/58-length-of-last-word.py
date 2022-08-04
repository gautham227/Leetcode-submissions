class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s=s.rstrip()
        s=s[::-1]
        try:
            return s.index(" ")
        except:
            return len(s)