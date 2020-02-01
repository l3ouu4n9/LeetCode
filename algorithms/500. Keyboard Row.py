"""
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

Example:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:

You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
"""

class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        row1 = ['Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P']
        row2 = ['A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L']
        row3 = ['Z', 'X', 'C', 'V', 'B', 'N', 'M']
        ret = []
        
        for s in words:
            one_row = True
            if s[0].upper() in row1:
                for ch in s.upper():
                    if ch not in row1:
                        one_row = False
                        break
            elif s[0].upper() in row2:
                for ch in s.upper():
                    if ch not in row2:
                        one_row = False
                        break
            elif s[0].upper() in row3:
                for ch in s.upper():
                    if ch not in row3:
                        one_row = False
                        break
            if one_row:
                ret.append(s)
                
        return ret
