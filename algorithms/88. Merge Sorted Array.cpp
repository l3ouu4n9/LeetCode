/*

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
  The number of elements initialized in nums1 and nums2 are m and n respectively.
  You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2

E.g.
  Input:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3
  Output: [1,2,2,3,5,6]
  
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr = 0;
        if(n == 0) return;
        for(int i = 0; i < nums1.size(); ++i){
            if(i < m){
                if(nums2[ptr] < nums1[i]){
                    nums1.insert(nums1.begin() + i, nums2[ptr]);
                    nums1.pop_back();
                    m += 1;
                    ptr += 1;
                }
            } else {
                nums1[i] = nums2[ptr];
                ptr += 1;
            }
            if(ptr == nums2.size()) break;
        }
        return;
    }
};
