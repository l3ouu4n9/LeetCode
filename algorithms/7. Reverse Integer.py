'''

Given a 32-bit signed integer, reverse digits of an integer.
E.g.
  Input: 123
  Output: 321
  
  Input: -123
  Output: -321
  
  Input: 120
  Output: 21
  
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.



Runtime: 61.78%
Memory: 63.44%

'''

import sys

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        s = str(x)
        if(s[0] == '-'):
            s = '-' + s[1::][::-1]
        else:
            s = s[::-1]

        while(len(s) > 1 and s[0] == '0'):
            s = s[1::]
        
        if(int(s) >= 2 ** 31 or int(s) < (-2) ** 31):
            return 0
        else:
            return int(s)
