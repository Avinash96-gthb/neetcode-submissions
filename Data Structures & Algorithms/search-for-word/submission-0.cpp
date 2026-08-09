class Solution {
public:
    int ROW;
    int COL;
    bool checkEveryCell(vector<vector<char>>& board, int row, int col, string word, int i){
        if (i == word.size()){
            return true;
        }
        if (row < 0 || col < 0 || row >= ROW || col >= COL || board[row][col] != word[i] || board[row][col] == '#'){
            return false;
        }
        board[row][col] = '#';
        bool res = checkEveryCell(board, row + 1, col, word, i+1) || checkEveryCell(board, row - 1, col, word, i+1) || checkEveryCell(board, row, col + 1, word, i+1) || checkEveryCell(board, row, col - 1, word, i+1);
        board[row][col] = word[i];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        ROW = board.size();
        COL = board[0].size();
        for (int i = 0; i < ROW; i++){
            for (int j = 0; j < COL; j++){
                if (checkEveryCell(board, i, j, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
