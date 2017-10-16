/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
/*
思路：
使用哈希表和滑动窗口（注意，这个窗口可能不是连着的，但是逻辑上是连着的）
*/
class Solution {
public:

vector<int> findAnagrams(string s, string p) {
    vector<int> ans; // 自己手动构建哈希表
    int n = s.size(), m = p.size();
    vector<int> h1(26), h2(26); // h2是一个滑动窗口

    for(int i = 0; i < m; i++)
        h1[p[i] - 'a']++;
    

    for(int i = 0; i < n; i++) {
        h2[s[i] - 'a']++; // 增加一个元素进入窗口
        if(i >= m) ｛
            h2[s[i - m] - 'a']--; // 从窗口中减去一个元素
        
        if(h1 == h2) ｛
            ans.push_back(i - m + 1);
    }

    return ans;
}
};