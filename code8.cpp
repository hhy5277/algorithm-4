/*
Given a string, 
you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string.

*/

class Solution {
public:
    string reverseWords(string s) {
    	string res = "";
        if (s == "") {
        	return res;
        }
        int front, end, cur;

        front = 0;

        for (int cur = 0; cur < s.length(); cur++) {
        	if (s[cur + 1] == '\0') {
        		end = cur;
        		for (int p = end; p >= front; p--) {
        		    res += s[p];
        	    }
        	    return res;
        	}

        	if (s[cur + 1] == ' ') {
        		end = cur;
        		for (int p = end; p >= front; p--) {
        		    res += s[p];
        	    }
        	    res += " ";
        	    front = cur + 2;
        	}
        }
    }
};