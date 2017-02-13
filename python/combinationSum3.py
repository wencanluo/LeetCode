'''
216. Combination Sum III   My Submissions QuestionEditorial Solution
Total Accepted: 31309 Total Submissions: 87224 Difficulty: Medium
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]
'''

class Solution(object):
    def getkey(self, nums):
        return ''.join(['%d'%x for x in sorted(nums)])
    
    def reversekey(self, snums):
        return [int(d) for d in snums]
    
    def combinationSum3_DP(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        A = []
        for j in range(n):
            A.append(set())
                
        for j in range(n):
            if j <= 9 and j>=1:
                A[j].add(self.getkey([j]))
    
        for i in range(1, k):
            B = []
            for j in range(n):
                B.append(set())
                
                for d in range(1,10):
                    if d-1 > j: continue
                
                    for x in A[j-d+1]:
                        B[j].add(self.getkey((self.reversekey(x) + [d])))
            
            A = B[:]
        
        return [self.reversekey(x) for x in A[n-1]]
    
    def combinationSum3_DFS(self, k, n, i, sum):
        if sum > n: return
        if len(self.v) == k and sum == n:
            self.r.append(self.v[:])
        
        if len(self.v) >= k: return
        
        for d in range(i, 10):
            self.v.append(d)
            self.combinationSum3_DFS(k, n, d+1, sum+d)
            del self.v[-1]
        
    def combinationSum3(self, k, n):
        self.r = []
        self.v = []
        
        self.combinationSum3_DFS(k, n, 1, 0)
        
        return self.r
    
    
if __name__ == '__main__':
    s = Solution()
    
    print s.combinationSum3(2, 5)
