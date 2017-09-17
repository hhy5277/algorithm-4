/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. 
Grid cells are connected horizontally/vertically (not diagonally). 
The grid is completely surrounded by water, 
and there is exactly one island (i.e., one or more connected land cells). 
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
ne cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
*/

/*
思路：
如果这个格子是1，那么开始计数。计数的方法有两种：
第一种方法：先加上4，然后判断如果旁边有陆地，那么就减去1
第二种方法：如果旁边是水，那么加1

显然，因为越界的问题，且数组旁边都是水，我们采取第二种方法会简单一些
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    	int row = grid.size();
    	int col = grid[0].size();

    	int sum = 0;

    	for (int i = 0; i < row; i++) {
    		for (int j = 0; j < col; j++) {
    			if (grid[i][j] == 0) {
    				continue;
    			}

    			int count_zero = 0;
    			// 判断上面的
    			if (i - 1 < 0 || grid[i - 1][j] == 0) { // 如果旁边是水（也就是0），那么周长加一。并且，我们把数组越界的情况也看作是0（因为数组的外面全是水，也就是0）
    				count_zero++;
    			}
    			// 判断下面的
    			if (i + 1 >= row || grid[i + 1][j] == 0) {
    				count_zero++;
    			}
    			// 判断左边的
    			if (j - 1 < 0 || grid[i][j - 1] == 0) {
    				count_zero++;
    			}
    			// 判断右边的
    			if (j + 1 >= col || grid[i][j + 1] == 0) {
    				count_zero++;
    			}

    			sum += count_zero;
    		}
    	}

    	return sum;
    }
};