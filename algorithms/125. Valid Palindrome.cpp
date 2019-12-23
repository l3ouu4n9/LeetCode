/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s == "") return true;
        int head = 0;
        int tail = s.length() - 1;
        while(head < tail){
            while(!isalnum(s[head])){
                if(head > s.length() - 1) return true;
                else ++head;
            }
            while(!isalnum(s[tail])) --tail;
            if(tolower(s[head]) != tolower(s[tail])) return false;
            ++head;
            --tail;
        }
        return true;
    }
};
