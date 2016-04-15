'''
169. Majority Element My Submissions QuestionEditorial Solution
Total Accepted: 107285 Total Submissions: 261719 Difficulty: Easy
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
'''

class Solution(object):
    def majorityElement_sorting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        keys = sorted(nums)
        return keys[len(nums)/2]
    
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        count = 1
        majority = nums[0]
        
        for num in nums[1:]:
            if num == majority:
                count += 1
            else:
                count -= 1
                
                if count == 0:
                    majority = num
                    count += 1
                
        
        return majority
    
        