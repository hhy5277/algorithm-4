/*
Given a string, determine if it is a palindrome, 
considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? 
This is a good question to ask during an interview.

For the purpose of this problem, 
we define empty string as valid palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int front = 0, end = n - 1;

        while (front < end) {
        	if (!((s[front] >= 'a' && s[front] <= 'z') || (s[front] >= 'A' && s[front] <= 'Z') || (s[front] >= '0' && s[front] <= '9'))) {
        		++front;
        		continue;
        	}
        	if (!((s[end] >= 'a' && s[end] <= 'z') || (s[end] >= 'A' && s[end] <= 'Z') || (s[end] >= '0' && s[end] <= '9'))) {
        		--end;
        		continue;
        	}

        	if (abs(s[front] - s[end]) == 32 || abs(s[front] - s[end]) == 0) {
        		if (((s[front] >= 'a' && s[front] <= 'z') || (s[front] >= 'A' && s[front] <= 'Z')) && (s[end] >= '0' && s[end] <= '9')) {
        			return false;

        		}
        		if (((s[end] >= 'a' && s[end] <= 'z') || (s[end] >= 'A' && s[end] <= 'Z')) && (s[front] >= '0' && s[front] <= '9')) {
        			return false;
        		}

                ++front;
                --end;
        	}
        	else {
        		return false;
        	}
        }

        return true;
    }
};