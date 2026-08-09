class Solution {
public:
    int maximum = INT_MIN;
    int dfs(vector<vector<int>>& grid, int row, int col){
        if (min(row, col) < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] == 0){
            return 0;
        }
        int sum = 1;
        grid[row][col] = 0;
        sum += dfs (grid, row + 1, col);
        sum += dfs (grid, row - 1, col);
        sum += dfs (grid, row, col + 1);
        sum += dfs (grid, row, col -1);

        maximum = max(maximum, sum);
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    int val = dfs(grid, i, j);
                }
            }
        }
        if (maximum == INT_MIN){
            return 0;
        }
        return maximum;
    }
};
