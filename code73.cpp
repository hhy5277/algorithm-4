/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/
/*
思路：
记录遍历s的每一个字母，并且记录s[i]到t[i]的映射，
当发现与已有的映射不同时，说明无法同构，直接return false。
但是这样只能保证从s到t的映射，不能保证从t到s的映射，
所以交换s与t的位置再重来一遍上述的遍历就OK了
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
        	return false;
        }

        int n = s.size();
        std::map<char, char> m;

        for (int i = 0; i < n; i++) {
        	if (!m.count(s[i])) {
        		m[s[i]] = t[i];
        	}
        	else if (m[s[i]] != t[i]) {
        		return false;
        	}
        }

        m.clear();

        for (int i = 0; i < n; i++) {
        	if (!m.count(t[i])) {
        		m[t[i]] = s[i];
        	}
        	else if (m[t[i]] != s[i]) {
        		return false;
        	}
        }

        return true;
    }
};