'''

Determine whether an integer is a palindrome.
An integer is a palindrome when it reads the same backward as forward.

E.g.
  Input: 121
  Output: true
  
  Input: -121
  Output: false
  Explanation: From left to right, it reads -121. 
  From right to left, it becomes 121-.
  
  Input: 10
  Output: false
  Explanation: Reads 01 from right to left.
  
'''

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        s = str(x)
        if(s == s[::-1]):
            return True
        else:
            return False
