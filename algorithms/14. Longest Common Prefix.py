'''
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

E.g.
  Input: ["flower","flow","flight"]
  Output: "fl"
  
  Input: ["dog","racecar","car"]
  Output: ""
  
  Runtime: 74.85%
  Memory: 66.25%

'''

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        strs.sort(key=len)
        done = 0
        s = ""
        if len(strs) > 0:
            for i in range(0, len(strs[0])):
                s += strs[0][i]
                for j in range(1, len(strs)):
                    if(s[i] != strs[j][i]):
                        s = s[:-1]
                        done = 1
                        break
                if(done):
                    break
        return s
