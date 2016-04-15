'''
137. Single Number II My Submissions QuestionEditorial Solution
Total Accepted: 80553 Total Submissions: 215131 Difficulty: Medium
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
'''

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        
        for i in range(32):
            
            count = 0
            for num in nums:
                count += (num>>i)&1
            count%=3
            
            if i==31 and count:
                res -= count<<31
            else:
                res |= count<<i
        return res
        
        