/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/
/*
思路：
用两个哈希表让pattern 和 str 互相做映射即可。
*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::vector<string> v;

        int n = str.size();
		string s;

		for (int i = 0; i < n; i++) {
		    if (str[i] != ' ') {
		    	s.push_back(str[i]);
		    }
		    else {
		    	v.push_back(s);
		    	s.clear();
		    }
		}

		v.push_back(s); // 把最后一个单词加入容器中

        if (v.size() != pattern.size()) {
        	return false;
        }

        std::map<char, string> m;

        for (int i = 0; i < pattern.size(); i++) {
        	if (m.count(pattern[i])) {
        		if (m[pattern[i]] != v[i]) {
        			return false;
        		}
        	}
        	else {
        		m[pattern[i]] = v[i];
        	}
        }

        std::map<string, char> m2;

        for (int i = 0; i < v.size(); i++) {
        	if (m2.count(v[i])) {
        		if (m2[v[i]] != pattern[i]) {
        			return false;
        		}
        	}
        	else {
        		m2[v[i]] = pattern[i];
        	}
        }

        return true;
    }
};