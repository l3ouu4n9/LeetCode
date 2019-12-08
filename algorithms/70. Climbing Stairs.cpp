/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec;
        vec.push_back(0);
        vec.push_back(1);
        vec.push_back(2);
        
        int num;
        for(int i = 3; i <= n; ++i){
            num = vec[i - 1] + vec[i - 2];
            vec.push_back(num);
        }
        
        return vec[n];
    }
};
