class Solution(object):
    def addBinary(self, a, b):
        p=int(a,2)
        q=int(b,2)
        sum=p+q
        res=bin(sum)[2:]
        return res
