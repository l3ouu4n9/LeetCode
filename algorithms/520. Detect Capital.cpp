/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:

Input: "USA"
Output: True

Example 2:

Input: "FlaG"
Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() > 1){
            // First capital
            if(word[0] >= 65 && word[0] <= 90){
                // First case
                if(word[1] >= 65 && word[1] <= 90)
                    for(int i = 2; i < word.length(); ++i){
                        if(word[i] < 65 || word[i] > 90) return false;
                // Third case
                } else {
                    for(int i = 2; i < word.length(); ++i){
                        if(word[i] < 97 || word[i] > 122) return false;
                    }
                }
            // Second case
            } else {
                for(int i = 1; i < word.length(); ++i){
                    if(word[i] < 97 || word[i] > 122) return false;
                }
            }
        } else {
            return true;
        }
        return true;
    }
};
