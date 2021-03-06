/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a^2 + b^2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

Input: 3
Output: False
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0 ; a * a <= c; ++a){
            double b = sqrt(c - a * a);
            if(b == (int) b) return true;
        }
        return false;
    }
};
