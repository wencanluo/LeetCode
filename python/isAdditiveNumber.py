'''
306. Additive Number   My Submissions QuestionEditorial Solution
Total Accepted: 10062 Total Submissions: 39272 Difficulty: Medium
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?
'''

class Solution(object):
    
    def add(self, num1, num2):
        X = [ord(d) - ord('0') for d in num1[::-1]]
        Y = [ord(d) - ord('0') for d in num2[::-1]]
        
        Z = [0]*(max(len(X), len(Y)) + 1)
        
        k = 0
        i = 0
        j = 0
        carry = 0
        while i < len(X) or j < len(Y):
            x = X[i] if i < len(X) else 0
            y = Y[j] if j < len(Y) else 0
            sum = x + y + carry
            Z[k] = sum%10
            carry = sum/10
            
            k += 1
            i += 1
            j += 1
        
        if carry:
            Z[k] = carry
        
        return ''.join([str(x) for x in Z[::-1]]).lstrip('0')
        
    
    def check_next(self, num, i, j, m):#return the end position of the third number
        if num[m] == '0' and i != m: return -1
        if num[i+1] == '0' and j != i+1: return -1
        
        print m, i, j, num[m:i+1], num[i+1:j+1]
        
        sum = self.add(num[m:i+1], num[i+1:j+1])
        print 'sum', sum
        
        if num[j+1:].startswith(sum):
            return j+len(sum)
        
        return -1
    
    def check(self, num, i, j):
        
        m = 0
        while j < len(num):
            k = self.check_next(num, i, j, m) #m is the start point of the first number
            print k
            
            if k==-1: return False
            if k == len(num)-1: return True
            
            m = i+1
            i = j
            j = k
            
            print m, i, j
        
        return True
        
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        
        n = len(num)
        
        for i in range(0, n-1): #first start number
            for j in range(i+1, n-1): #second start number
                #check invidate ones
                
                if num[0] == '0' and i > 1: break
                if n-j < max(i+1, j-i): break #the remaining numbers are not long enough
                
                print i, j
                if self.check(num, i, j):
                    return True
        
        return False
                

if __name__ == '__main__':
    s = Solution()
    
    print s.isAdditiveNumber("011235")
    
                
        