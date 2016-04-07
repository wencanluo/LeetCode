'''
69. Sqrt(x) My Submissions QuestionEditorial Solution
Total Accepted: 90037 Total Submissions: 358111 Difficulty: Medium
Implement int sqrt(int x).

Compute and return the square root of x.
'''

class Solution(object):
    def mySqrtBinarySearch(self, x, i, j):
        if i==j:
            return i
        
        if i==j-1:
            if i*i >= x: 
                return i
            else:
                if j*j > x: return i
                return j
        
        mid = (i+j)/2
        mid2 = mid*mid
        
        if  mid2 > x:
            return self.mySqrtBinarySearch(x, i, mid-1)
        else:
            return self.mySqrtBinarySearch(x, mid, j)
        
        
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0: return -1 #not defined
        
        return self.mySqrtBinarySearch(x, 0, x)
    