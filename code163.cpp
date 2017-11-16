/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        helper(res, temp, s);
        return res;
    }

    /*
    作用：去找字符串中的回文串
    参数1：也就是题目中要求的返回值
    参数2：临时保存回文串数组
    参数3：需要查找的字符串
    */
    void helper(vector<vector<string>> & res, vector<string> temp, string s){
        if (s.size() == 0) { // 结束递归
            res.push_back(temp);
            return ;
        }

        for (int i = 0; i < s.size(); i++) {
            string t = s.substr(0, i + 1);
            if (isPalindrome(t)) {
                temp.push_back(t);
                helper(res, temp, s.substr(i + 1, s.size() - t.size()));
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) return false;
        }

        return true;
    }
};