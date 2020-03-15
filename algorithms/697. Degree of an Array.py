"""
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:

Input: [1, 2, 2, 3, 1]
Output: 2

Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:

Input: [1,2,2,3,1,4,2]
Output: 6

Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
"""

class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        c = collections.Counter(nums)
        l = []
        freq = 0
        for i in c:
            if c[i] > freq:
                l = [i]
                freq = c[i]
            elif c[i] == freq:
                l.append(i)
        
        difference = len(nums)
        for i in l:
            ptr1 = nums.index(i)
            ptr2 = len(nums) - nums[::-1].index(i)
            if ptr2 - ptr1 < difference:
                difference = ptr2 - ptr1
        return difference
