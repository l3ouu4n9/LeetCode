/*

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0; i <= rowIndex; ++i){
            int tmp = 1;
            for(int j = 1; j < i; ++j){
                ans[j] = tmp + ans[j];
                tmp = ans[j] - tmp;
            }
            ans.push_back(1);
        }
        return ans;
    }
};
