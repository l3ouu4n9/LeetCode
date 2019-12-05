'''
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

E.g.

  Input: 4
  Output: "1211"
'''

class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = "1"
        for i in range(n-1):
            num = 0
            prev = ""
            new_s = ""
            for ch in s:
                if prev == "":
                    prev = ch
                    num += 1
                else:
                    if prev == ch:
                        num += 1
                    else:
                        new_s += str(num) + prev
                        prev = ch
                        num = 1
            new_s += str(num) + prev
            s = new_s
                
            
        return s
