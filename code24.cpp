/*
Given a string, 
find the first non-repeating character in it and return it's index. 
If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
*/
/*
思路：使用哈希表把每个元素出现的次数都记录下来
*/
class Solution {
public:
    int firstUniqChar(string s) {
        if (s == "") {
        	return -1;
        }

        std::map<char, int> m;

        int n = s.size();

        for (int i = 0; i < n; i++) {
        	m[s[i]] = 0;
        }

        for (int i = 0; i < n; i++) {
        	m[s[i]]++;
        }


    	for (int i = 0; i < n; i++) {
    		if (m[s[i]] == 1) {
    			return i;
    		}
    	}

    	return -1;
    }
};