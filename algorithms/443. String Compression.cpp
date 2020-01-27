/*
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.
 
Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
 
Example 2:

Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
 
Example 3:

Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
 
Note:

All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int read_ptr = 0, write_ptr = 0, curr_ptr = 0;
        while(read_ptr < chars.size()){
            if(read_ptr + 1 == chars.size() || chars[read_ptr + 1] != chars[read_ptr]){
                chars[write_ptr] = chars[curr_ptr];
                ++write_ptr;
                if(read_ptr > curr_ptr){
                    string s = to_string(read_ptr - curr_ptr + 1);  
                    for(int i = 0; i < s.length(); ++i){
                        chars[write_ptr] = s[i];
                        ++write_ptr;
                    }
                }
                curr_ptr = read_ptr + 1;
            }
            ++read_ptr;
        }
        return write_ptr;  
    }
};
