'''
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

E.g.
  Input: "III"
  Output: 3
  
  Input: "IX"
  Output: 9
  
  Input: "LVIII"
  Output: 58
  
  Explanation: L = 50, V= 5, III = 3.
  Input: "MCMXCIV"
  
  Output: 1994
  Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

'''

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        dict = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        max_value = 1
        sum = 0
        for ch in s[::-1]:
            if dict[ch] >= max_value:
                max_value = dict[ch]
                sum += dict[ch]
            else:
                sum -= dict[ch]
                
        return sum
