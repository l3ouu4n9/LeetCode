"""
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
"""

class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        ltr = []
        rtl = []
        prev = float("inf")
        
        for ch in S:
            if ch == C:
                prev = 0
            else:
                if prev != "inf":
                    prev += 1
            ltr.append(prev)
        
        prev = float("inf")
        for ch in S[::-1]:
            if ch == C:
                prev = 0
            else:
                if prev != "inf":
                    prev += 1
            rtl.append(prev)
        
        rtl.reverse()
        for i in range(0, len(ltr)):
            ltr[i] = min(ltr[i], rtl[i])
        
        return ltr
