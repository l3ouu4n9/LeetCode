/*

Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

E.g.

Input: [1,3,5,6], 5
Output: 2
Input: [1,3,5,6], 2
Output: 1
Input: [1], 0
Output: 0
Input: [], 2
Output: 0

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = nums.size() / 2;
        int top = nums.size() - 1;
        int buttom = 0;
        if(nums.size() == 0 || target <= nums[0])return 0;
        else if(target > nums[top])return nums.size();
        else{
            while(top != pos && buttom != pos){
                if(target == nums[pos])return pos;
                else if(target > nums[pos]){
                    buttom = pos;
                    pos = (buttom + top) / 2;
                }else{
                    top = pos;
                    pos = (buttom + top) / 2;
                }
            }
            if(top == buttom)return 0;
            else if(pos == buttom)return pos + 1;
            else return pos;
        }
        
    }
};
