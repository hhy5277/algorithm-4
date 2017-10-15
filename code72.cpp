/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/
class Solution {
public:
    string countAndSay(int n) {
        string str_result = "1";

        if (n == 1) {
        	return str_result;
        }
        else {
        	n = n - 1;
        }

        while (n--) {
        	str_result = the_next_number(str_result);
        }

        return str_result;
    }

    string the_next_number(string s) {
    	string temp;
    	string temp_last;

    	temp.push_back(s[0]);

    	int i = 1;
    	int n = s.size();

	    if (n > 1) {
	    	while (i != n) {
	    		if (s[i] == s[i - 1]) {
	    			temp.push_back(s[i]);
	    			i++;
	    		}
	    		else {
	    			temp_last.push_back(temp.size() + 48);
	    			temp_last.push_back(temp[0]);
	    			temp.clear();
	    			temp.push_back(s[i]);
	    			i++;
	    		}
	    	}
	    }
	    if (n != 0) {
	    	temp_last.push_back(temp.size() + 48);
	    	temp_last.push_back(temp[0]);
	    }

    	return temp_last;
    }
};