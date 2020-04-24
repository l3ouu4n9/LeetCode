"""
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
"""

class Solution(object):
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False
        
        if A == B:
            c = collections.Counter(A)
            print(len(c), len(A))
            if len(c) == len(A):
                return False
            else:
                return True
        
        idx1 = -1
        idx2 = -1
        for i in range(len(A)):
            if A[i] != B[i]:
                if idx1 == -1:
                    idx1 = i
                else:
                    if idx2 != -1:
                        return False
                    else:
                        idx2 = i
                
        if idx1 != -1 and idx2 != -1:
            A = A[0:idx1] + A[idx2] + A[idx1+1:idx2] + A[idx1] + A[idx2+1:]
            if A == B:
                return True
        
        return False
