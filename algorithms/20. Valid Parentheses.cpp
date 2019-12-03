/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
  1. Open brackets must be closed by the same type of brackets.
  2. Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

E.g.
  Input: "()"
  Output: true
  
  Input: "()[]{}"
  Output: true
  
  Input: "(]"
  Output: false
  
  Input: "([)]"
  Output: false
  
  Input: "{[]}"
  Output: true
  
  Runtime: 100%
  Memory: 95.35%

*/

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')stack.push_back(s[i]);
            else{
                if(stack.size() == 0)return false;
                else{
                    switch (s[i]){
                        case ')':
                            if(stack[stack.size() - 1] == '(')stack.pop_back();
                            else return false;
                            break;
                        case ']':
                            if(stack[stack.size() - 1] == '[')stack.pop_back();
                            else return false;
                            break;
                        case '}':
                            if(stack[stack.size() - 1] == '{')stack.pop_back();
                            else return false;
                            break;
                        default:
                            return false;
                            break;
                    }
                }
            }
        }
        if(stack.size() == 0)return true;
        else return false;
    }
};
