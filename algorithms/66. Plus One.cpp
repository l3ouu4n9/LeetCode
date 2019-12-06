/*

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

E.g.
  Input: [1,2,3]
  Output: [1,2,4]
  
  Input: [4,3,2,1]
  Output: [4,3,2,2]
  
  Input: [9,9]
  Output: [1,0,0]
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1] += 1;
        for(int i = digits.size() - 1; i >= 0; --i){
            if(digits[i] == 10){
                if(i == 0){
                    digits[i] = 0;
                    digits.insert(digits.begin(), 1);
                }
                else{
                    digits[i] = 0;
                    digits[i - 1] += 1;
                }
            }else break;
        }
        return digits;
    }
};
