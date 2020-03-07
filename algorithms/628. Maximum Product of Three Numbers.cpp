/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6
 

Example 2:

Input: [1,2,3,4]
Output: 24

Note:

The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        
        // all positive
        int ppp = nums[size - 1] * nums[size - 2] * nums[size - 3];
        // 1 positive, 2 negative
        int pnn = nums[0] * nums[1] * nums[size - 1];
        // 3 negative
        int nnn = nums[0] * nums[1] * nums[2];
        
        return max(max(ppp, pnn), nnn);
    }
};