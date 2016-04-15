'''
136. Single Number My Submissions QuestionEditorial Solution
Total Accepted: 123297 Total Submissions: 249373 Difficulty: Medium
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
'''

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        r = 0
        for num in nums:
            r = r ^num
        
        return r