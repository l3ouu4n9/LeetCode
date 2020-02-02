/*
Given an integer, return its base 7 string representation.

Example 1:

Input: 100
Output: "202"

Example 2:

Input: -7
Output: "-10"

Note: The input will be in range of [-1e7, 1e7].
*/

class Solution {
public:
    string convertToBase7(int num) {
        string s;
        int absNum = abs(num);
        
        if(num == 0) return "0";
        
        while(absNum){
            s = to_string(absNum % 7) + s;
            absNum /= 7;
        }
        if(num < 0) s = '-' + s;
        
        return s;
    }
};
