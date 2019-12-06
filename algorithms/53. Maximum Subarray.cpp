/*

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

E.g.

  Input: [-2,1,-3,4,-1,2,1,-5,4],
  Output: 6
  Explanation: [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_final = nums[0];
        int max_now = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            max_now = max(nums[i], max_now + nums[i]);
            max_final = max(max_final, max_now);
        }
        return max_final;
    }
};
