/*
Determine whether an integer is a palindrome. 
Do this without extra space.
*/
/*
得出这个数字的倒过来的那个数字tmp，然后和x比较是否相等。
*/
class Solution {
public:
    bool isPalindrome(int x) {
        int tmp = 0;
        int temp_x = x;

        while (temp_x > 0) {
        	tmp *= 10;
            tmp += temp_x % 10;
            temp_x /= 10;
        }

        if (x == tmp) {
        	return true;
        }
        else {
        	return false;
        }
    }
};