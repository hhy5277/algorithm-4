class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = n - 1;
        bool flag = true;

        while (start < end) {
        	if (s[start] == s[end]) {
        		start++;
        		end--;
        	}
        	else {
	        	if (flag) {
	        		flag = false;

	        		if ((s[start + 1] == s[end])) {
	        			start++;
	        		}
	        		else if (s[start] == s[end - 1]) {
	        			end--;
	        		}
	        		else {
	        			return false;
	        		}
	        	}
	        	else {
	        		return false;
	        	}
        	}
        }

        return true;
    }
};