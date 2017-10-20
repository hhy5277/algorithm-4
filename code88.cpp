/*
Given two strings A and B, 
find the minimum number of times A has to be repeated such that B is a substring of it. 
If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), 
B is a substring of it; 
and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/
/*
思路：
重复多少次之后能够使得A包含B，
关键在于何时停止重复，
显然，如果A的repeat后的长度大于B时，即可停止搜索了，
因为在此长度下A都不能包含B，那么repat的次数再大也没用。
*/
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
    	int num = 1;
    	string s = A;

        while (s.size() < B.size()) {
        	s += A;
            num++;
        }

        if (s.find(B) != -1) {
        	return num;
        }

        s += A;
        num++;

        if (s.find(B) != -1) {
        	return num;
        }

        return -1;
    }
};