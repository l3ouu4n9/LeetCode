"""
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:

Input: "aba"
Output: True

Example 2:

Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:

The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
"""

class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        head = 0
        tail = len(s) - 1
        while head < tail:
            if s[head] == s[tail]:
                head += 1
                tail -= 1
            else:
                delete_head = s[head+1:tail+1]
                delete_tail = s[head:tail]
                return delete_head == delete_head[::-1] or delete_tail == delete_tail[::-1]
        return True
