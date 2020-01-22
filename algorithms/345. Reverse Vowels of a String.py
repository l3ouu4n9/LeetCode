"""
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"

Example 2:

Input: "leetcode"
Output: "leotcede"

Note:

The vowels does not include the letter "y".
"""

class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        string = list(s)
        head = 0
        tail = len(string) - 1
        l = ["A", "E", "I", "O", "U", "a", "e", "i", "o", "u"]
        while head <= tail:
            while string[head] not in l and head < tail:
                head += 1
            if head == tail:
                break
            else:
                while string[tail] not in l and head < tail:
                    tail -= 1
                if head == tail:
                    break
                else:
                    tmp = string[head]
                    string[head] = string[tail]
                    string[tail] = tmp
                    head += 1
                    tail -= 1
        return ''.join(string)
