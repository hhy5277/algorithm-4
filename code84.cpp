/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        int position = n - 1;

        for (int i = n - 1; i >= 0; i--) {
        	if (s[i] != ' ') {
        		break;
        	}
        	else {
        		position--;
        	}
        }

        for (int i = position; i >= 0; i--) {
        	if (s[i] != ' ') {
        		count++;
        	}
        	else {
        		break;
        	}
        }

        return count;
    }
};