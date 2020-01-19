/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:

You may assume that the array does not change.
There are many calls to sumRange function.
*/
class NumArray {
private:
    vector<int> q;
public:
    NumArray(vector<int>& nums) {
        q = nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        while(i <= j){
            sum += q[i];
            i += 1;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
