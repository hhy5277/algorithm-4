class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cur(n, string(n, '.')); // 初始化棋盘，所有的位置都没有摆放皇后
        dfs(res, cur, n, 0);
        return res;
    }
    
    void dfs(vector<vector<string>> &res, vector<string> &cur, int &n, int row) {
        if (row == n) { // 当超出行数超出了棋盘，则把这次搜索的结果放入res中。
            res.push_back(cur);
            return;
        }
        
        for (int j = 0; j < n; j++) {
            if (isValid(cur, n, row, j)) { // 判断在(row, j)处是否可以放一个皇后
                cur[row][j] = 'Q'; // 如果可以，则放一个皇后
                dfs(res, cur, n, row + 1); // 继续在下一行找一个位置放皇后
                cur[row][j] = '.'; // 因为需要找到所有可能的情况，所以必然需要对每一行进行回退。去判断这一行的下一列是否可以放皇后。
            }
        }
    }
    
    bool isValid(vector<string> &cur, int &n, int row, int col) {
        // 检查列
        for (int i = 0; i < row; i++) {
            if (cur[i][col] == 'Q') {
                return false;
            }
        }
        // 检查反斜线
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (cur[i][j] == 'Q') {
                return false;
            }
        }
        // 检查斜线
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (cur[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};