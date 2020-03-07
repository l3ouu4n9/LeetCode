/*
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:

Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:

Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.

Note: The n belongs to [1, 10,000].
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() == 0) return true;
        bool modified = false;
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] > nums[i + 1]){
                if(!modified){
                    if(i == 0) {
                        modified = true;
                        nums[i] = nums[i + 1];
                    } else if(i == nums.size() - 2){
                        modified = true;
                        nums[i + 1] = nums[i];
                    } else {
                        modified = true;
                        if(nums[i - 1] <= nums[i + 1]) nums[i] = nums[i + 1];
                        else nums[i + 1] = nums[i];
                    }
                } else return false;
            }
        }
        return true;
    }
};
