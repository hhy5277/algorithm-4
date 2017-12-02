/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/
/*
思路：
先按照y轴交换，再按照主对角线交换
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // 按照y轴进行交换
        for (int row = 0; row < rows; ++row) {
        	for (int col = 0; col < cols / 2; ++col) {
        		swap(matrix[row][col], matrix[row][cols - 1 - col]);
        	}
        }

        // 按照主对角线进行交换
        for (int row = 0; row < rows; ++row) {
        	for (int col = 0; col < cols - 1 - row; ++col) {
        		swap(matrix[row][col], matrix[cols - 1 - col][rows - 1 - row]);
        	}
        }
    }
};