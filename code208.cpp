class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	int rows = board.size();
    	int cols = board[0].size();
    	int index = 0;
    	int n = word.size();

    	bool* visited = new bool[rows * cols];
        memset(visited,0,rows*cols);

    	for (int row = 0; row < rows; ++row) {
    		for (int col = 0; col < cols; ++col) {
                if (_exist(board, row, col, word, 0, visited)) {
                	return true;
                }
    		}
    	}

    	return false;
    }

    bool _exist(vector<vector<char>>& board, int row, int col, string word, int index, bool* visited) {
    	if (word[index] == '\0') {
    		return true;
    	}

    	bool has_path = false;
    	if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == word[index] && !visited[row*board[0].size() + col]) {
    		++index;
    		visited[row * board[0].size() + col] = true;
    		has_path = _exist(board, row - 1, col, word, index, visited)
    		       ||  _exist(board, row + 1, col, word, index, visited)
    		       ||  _exist(board, row, col - 1, word, index, visited)
    		       ||  _exist(board, row, col + 1, word, index, visited);

    		if (!has_path) {
    			--index;
    			visited[row * board[0].size() + col] = false;
    		}
    	}

    	return has_path;
    }
};