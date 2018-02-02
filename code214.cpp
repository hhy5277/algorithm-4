/*
Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"

["e","e","e","e","e","e","n","n","n","n"]
  0   1   2   3   4   5   6   7   8   9
target e

["e","e","e","k","q","q","q","v","v","y"]
  0   1   2   3   4   5   6   7   8   9
target "v"


"p","p","p","p","p","p","p","p","p","p","r","r","r","r","r","r"
"s","s","s","s","s","s","s","s","s","s","s","s","s","s","s","s"
x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x"
"x","x","x","x","x","x","x","x","y","y","y","y","y","y","y","y"
"p"
*/

/*
思路：
采用二分查找法的思想
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int length = letters.size();
        int left = 0;
        int right = length - 1;
        int middle = 0;

        while (left <= right) {
        	middle = left + (right - left) / 2;

        	if (letters[middle] == target) {
        		if (letters[middle] != letters[middle + 1]) {
            		return letters[(middle + 1) % length];
        		}
        		else {
        			left = middle + 2;
        		}
        	}
        	else if (letters[middle] < target) {
        		if (middle + 1 == length) {
        			return letters[0];
        		}

        		if (target < letters[middle + 1]) {
        			return letters[middle + 1];
        		}
        		else {
            		left = middle + 1;
        		}
        	}
        	else {
        		if (middle + 1 == length) {
        			return letters[middle];
        		}

        		if (target > letters[middle - 1]) {
        			return letters[middle];
        		}
        		else {
            		right = middle - 1;
        		}
        	}
        }

        return letters[middle % (length - 1)];
    }
};





