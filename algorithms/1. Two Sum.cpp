/*
  Given nums = [2, 7, 11, 15], target = 9,

  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            int tmp = target - nums[i];
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[j] == tmp){
                    ans.push_back(i);
                    ans.push_back(j);
                    i = nums.size();
                    j = nums.size();
                }
            }
        }
        return ans;
    }
};
