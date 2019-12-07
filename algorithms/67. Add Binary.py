'''

Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

E.g.

  Input: a = "11", b = "1"
  Output: "100"
  
  Input: a = "1010", b = "1011"
  Output: "10101"

'''

class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        result = ""
        max_length = max(len(a), len(b))
        a = a.zfill(max_length)
        b = b.zfill(max_length)
        carry = 0
        
        for i in range(max_length - 1, -1, -1):
            if carry == 0:
                if a[i] == b[i]:
                    if a[i] == '1':
                        carry = 1
                    result = '0' + result
                else:
                    result = '1' + result
            else:
                if a[i] == b[i]:
                    if a[i] != '1':
                        carry = 0
                    result = '1' + result
                else:
                    result = '0' + result
        if carry == 1:
            result = '1' + result
        
        return result
                
