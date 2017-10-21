/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
*/
/*
思路：
1、暴力破解
2、KMP算法
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();

        for(int i = 0; i <= m-n; i ++) {
            int j;

            for(j = 0; j < n; j ++) {
                if(haystack[i+j] != needle[j]) {
                	break;
                }
            }

            if(j == n) {
            	return i;
            }
        }

        return -1;
    }
};