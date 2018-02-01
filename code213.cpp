/*
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: True
Explanation:
1234
5123
9512

In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
Example 2:

Input: matrix = [[1,2],[2,2]]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
*/

/*
思路：
先对数组第一行的每个元素的斜线进行判断，
然后再来对数组第一列的每个元素的斜线进行判断。
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // 先对数组第一行的每个元素的斜线进行判断
        for (int i = 0; i < cols; ++i) {
        	int row = 0, col = i; // 元素起始点
        	while (row >= 0 && row + 1 < rows && col >= 0 && col + 1 < cols) {
        		if (matrix[row][col] != matrix[row + 1][col + 1]) {
        			return false;
        		}
        		else {
        			++row;
        			++col;
        		}
        	}
        }

        // 再来对数组第一列的每个元素的斜线进行判断
        for (int i = 1; i < rows; ++i) {
        	int row = i, col = 0; // 元素起始点
        	while (row >= 0 && row + 1 < rows && col >= 0 && col + 1 < cols) {
        		if (matrix[row][col] != matrix[row + 1][col + 1]) {
        			return false;
        		}
        		else {
        			++row;
        			++col;
        		}
        	}
        }

        return true;
    }
};