class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(int row, int col, vector<string>& board){
        for (int i = row - 1; i >= 0; i--){
            if (board[i][col] == 'Q'){
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if (board[i][j] == 'Q'){
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++){
            if (board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void dfs(int row, vector<string>& board){
        if (row == board.size()){
            res.push_back(board);
        }

        for (int i = 0; i < board.size(); i++){
            if (isSafe(row, i, board)){
                board[row][i] = 'Q';
                dfs(row + 1, board);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(0, board);
        return res;
    }
};
