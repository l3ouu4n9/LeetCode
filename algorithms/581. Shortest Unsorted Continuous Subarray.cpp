/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:

Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:

Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        int begin = -1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != sorted_nums[i]){
                begin = i;
                break;
            }
        }
        int end = -1;
        for(int i = nums.size() - 1; i >= 0; --i){
            if(nums[i] != sorted_nums[i]){
                end = i + 1;
                break;
            }
        }
        
        return (end - begin);
    }
};
