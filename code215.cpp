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
*/

/*
思路：
采用二分查找法的思想
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target)
            return letters.front();
        int left = 0, right = letters.size() - 1;
        while (left < right)  {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return letters[left];
    }
};