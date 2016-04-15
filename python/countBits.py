'''
Counting Bits My Submissions QuestionEditorial Solution
Total Accepted: 13459 Total Submissions: 24151 Difficulty: Medium
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

'''

class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        if num==0: return [0]
        if num==1: return [0,1]
        
        bits = [0, 1]
        k = 1
        i = 2
        while True:
            k = 2*k
            
            for j in range(i,2*k):
                if j> num: break
            
                bits.append(1+bits[j-k])
            
            i = 2*k
            if j > num: break
        
        return bits
            