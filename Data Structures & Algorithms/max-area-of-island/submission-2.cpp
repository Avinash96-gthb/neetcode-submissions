class Solution {
public:
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

        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};
