/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

class Solution {
public:
    bool isHappy(int n) {
        vector<int> have_exist;
        vector<int>::iterator it;
        int num = 0;
        
        it = find(have_exist.begin(), have_exist.end(), num);
        
        while(it == have_exist.end()){
            have_exist.push_back(n);
            while(n != 0){
                num += pow(n % 10, 2);
                n /= 10;
            }
            if(num == 1) break;
            else{
                it = find(have_exist.begin(), have_exist.end(), num);
                n = num;
                num = 0;
            }
        }
        if(num == 1) return true;
        else return false;
    }
};
