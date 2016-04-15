'''
190. Reverse Bits My Submissions QuestionEditorial Solution
Total Accepted: 59260 Total Submissions: 202612 Difficulty: Easy
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
'''

class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        r = 0
        for i in range(32):
            r = r<<1
            
            if n%2==1:
                r += 1
            
            n = n>>1
        
        return r