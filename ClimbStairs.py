class Solution(object):
    def climbStairs(self, n):
        if n<=2:
            return n
        ons=1
        tws=2
        for i in range(3,n+1):
            curr=ons+tws
            ons=tws
            tws=curr
        return curr

        
