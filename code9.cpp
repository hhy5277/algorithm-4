class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if ((r * c) != (nums.size() * nums[0].size())) { // 如果原来的和新的数组元素的个数不等，不用转换
        	return nums;
        }

        vector<vector<int>> newMatrix(r);

        int i = -1, j = 0, k = -1, l = 0; //其中的i和j用来标识原始矩阵的
        int count = 0;

        while (count != r * c) { // 使用while来模拟对两个二维数组同时遍历的过程
        	if (j % nums[0].size() == 0) { // 这一行遍历完了，换成下一行
        		i++;
        	}
        	if (l % c == 0) {
        		k++;
        	}

        	newMatrix[k][l] = nums[i][j];
        	l = (++l) % c;
        	j = (++j) % nums[0].size();
        	count++;
        }

        return newMatrix;
    }
};