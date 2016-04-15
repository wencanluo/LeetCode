'''
191. Number of 1 Bits My Submissions QuestionEditorial Solution
Total Accepted: 85256 Total Submissions: 227336 Difficulty: Easy
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should retur
'''

class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        count = 0
        
        while n > 0:
            if n%2==1:
                count += 1
                
            n=n/2
            
        return count
            