/*
Given a positive integer, 
return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/
/*
思路：
这题实际上是10进制转换为26进制，但是，这里有一个细节和转换二进制不同：
因为，二进制是从0到1的，而不是从1到2的；而这题26进制是从1到26的。
所以，是 n = (n - 1) / 26;
而不是 n /= 26;
*/
class Solution { 
public:
    string convertToTitle(int n) {
    	string s;

    	if (n <= 26) {
    		s.push_back('A' + n - 1);

    		return s;
    	}

        while (n > 0) {
        	int remain = n % 26;

        	if (remain == 0) {
        		s.push_back('Z');
        	}
        	else {
        		s.push_back('A' + remain - 1);
        	}

        	n = (n - 1) / 26;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};