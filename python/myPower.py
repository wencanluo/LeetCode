'''
50. Pow(x, n) My Submissions QuestionEditorial Solution
Total Accepted: 87042 Total Submissions: 312142 Difficulty: Medium
Implement pow(x, n).
'''

class Solution(object):
    
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0: return 1.0
        if n==1: return x
        if n==-1: return 1.0/x
        
        pow2 = self.myPow(x, n/2)
        
        if n%2==0:
            return pow2*pow2
        else:
            return pow2*pow2*x
        
        