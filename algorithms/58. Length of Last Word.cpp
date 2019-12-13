/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

E.g.

  Input: "Hello World"
  Output: 5

*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s == "") return 0;
        size_t pos = s.find_last_of(" ");
        while(pos == s.length() - 1){
            s = s.substr(0, s.length() - 1);
            pos = s.find_last_of(" ");
            if(s == "") return 0;
        }
        if(pos == string::npos){
            return s.length();
        } else {
            return s.substr(pos+1).length();
        }
    }
};
