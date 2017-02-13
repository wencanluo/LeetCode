'''
322. Coin Change   My Submissions QuestionEditorial Solution
Total Accepted: 20707 Total Submissions: 83203 Difficulty: Medium
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
'''

class Solution(object):
    
    def coinChange_DFS(self, coins, amount, k, total):
        print self.changes
        print amount, k, total
        
        if self.state == 0 or self.state==1: return
        
        if total == amount: 
            self.state = 0
            return
        
        if k >= len(coins): 
            self.state = 1
            return 
        
        
        if total > amount:
            
        
        
        
        #use the max coin
        while amount - total >= coins[k]:
            self.changes.append(coins[k])
            total += coins[k]
            
            r = self.coinChange_DFS(coins, amount, k, total)
            if r == 0: return 0
            del self.changes[-1]
            
        #use the next coin
        r = self.coinChange_DFS(coins, amount, k+1, total)
        if r == 0: return 0
        
        
        
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        
        self.state = -1
        self.changes = []
        total = 0
        
        coins = sorted(coins, reverse = True)
        
        self.coinChange_DFS(coins, amount, 0, total)
        
        if len(self.changes) == 0: return -1
        
        return len(self.changes)
    
    
if __name__ == '__main__':
    s = Solution()
    
    print s.coinChange([1, 2, 5], 11)
    print s.changes
    
    #print s.coinChange([2], 5)
    #print s.changes
    
        