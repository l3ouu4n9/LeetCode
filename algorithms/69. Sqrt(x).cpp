/*

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

E.g.
  Input: 4
  Output: 2
  
  Input: 8
  Output: 2
*/

class Solution {
public:
    int mySqrt(int x) {
        double num = x;
        num = sqrt(x);
        return int(num);
    }
};
