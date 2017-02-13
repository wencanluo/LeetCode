class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        
        r = set()
        
        nums = sorted(nums)
        
        N = len(nums)
        
        S2 = []
        for i in range(N):
            for j in range(i+1, N):
                sum = nums[i] + nums[j]
                S2.append((sum, (i, j)))
        
        S2 = list(set(S2))
        
        S = sorted(S2, key=lambda x: x[0]) #sorted
        
        #two sum
        left = 0
        right = len(S) - 1
        
        while left < right:
            sum = S[left][0] + S[right][0]
            
            if sum == target:
                index1 = S[left][1]
                index2 = S[right][1]
                
                k = right
                
                while k > left and S[left][0] + S[k][0] == target:
                    index2 = S[k][1]
                    k = k - 1
                    
                    if index1[0] == index2[0]: continue
                    if index1[0] == index2[1]: continue
                    if index1[1] == index2[0]: continue
                    if index1[1] == index2[1]: continue
                    
                    x = sorted([nums[index1[0]],nums[index1[1]],nums[index2[0]],nums[index2[1]]])
                    r.add((x[0],x[1],x[2],x[3])) 
                
                left += 1
                
            elif sum < target:
                left += 1
            else:
                right -= 1
        
        return [list(x) for x in r]
        
if __name__ == '__main__':
    s = Solution()
    
    print s.fourSum([2,1,0,-1], 2)
     