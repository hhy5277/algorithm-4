/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/
/*
思路：
由于给定矩形是个正方形，我们计算环数时用n / 2来计算，
若n为奇数时，此时最中间的那个点没有被算在环数里，所以最后需要单独赋值，
这一题下标转换问题是难点
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 1));
        int val = 1, p = n; // p是每次轮回开始后，还没填的数组的长度。（因为刚开始的时候都没有填，所以是n）
        for (int i = 0; i < n / 2; ++i, p -= 2) { // i是每次轮回的起始行位置（数组下标）
            for (int col = i; col < i + p; ++col) // 从左往右（因为可以填的范围是数组还没有填的长度p，所以是到 i + p）
                res[i][col] = val++;
            for (int row = i + 1; row < i + p; ++row) // 从上到下
                res[row][i + p - 1] = val++;
            for (int col = i + p - 2; col >= i; --col) // 从右往左
                res[i + p - 1][col] = val++;
            for (int row = i + p - 2; row > i; --row) // 从下往上
                res[row][i] = val++;
        }
        if (n % 2 != 0) res[n / 2][n / 2] = val;

        return res;
    }
};