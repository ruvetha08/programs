class Solution(object):
    def lengthOfLastWord(self, s):

        w=s.split()
        return len(w[-1])
