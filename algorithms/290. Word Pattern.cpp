/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*/

class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        pat_dict = {}
        l = str.split(" ")
        
        if len(l) != len(pattern):
            return False
        
        for i in range(0, len(pattern)):
            if not pat_dict.has_key(pattern[i]):
                if l[i] in pat_dict.values():
                    return False
                else:
                    pat_dict[pattern[i]] = l[i]
            elif pat_dict[pattern[i]] != l[i]:
                return False
        return True
