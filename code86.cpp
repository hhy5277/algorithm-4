/*
Write a function to find the longest common prefix string amongst an array of strings.
例如：
"abcdefg"
"abcdefghijk"
"abcdfghijk"
"abcef"
上面的字符串数组的最长公共前缀就是"abc"。
*/
/*
思路：
把第一行的字符串存在一个临时的字符串里面，
然后让这个临时的字符串去和剩下的字符串进行比较，
当发现字符不同的时候，在临时的字符串中的那个位置替换成'\0'。
以此类推......
*/
class Solution {  
public:  
    string longestCommonPrefix(vector<string>& strs) {  
        if(strs.size()==0) {
            return "";
        }

        string str;

        for(int i=0;i<strs[0].size();i++){  
            str.push_back(strs[0][i]);
        }

        str.push_back('\0');

        for(int i = 1; i < strs.size(); i++){  
            int j = 0;

            while(str[j] && strs[i][j] && (str[j] == strs[i][j])) {
                j++;
            }

            str[j] = '\0';
        }

        return string(str);
    }
};