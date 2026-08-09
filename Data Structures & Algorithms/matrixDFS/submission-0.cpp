class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visited){

        if (min(row, col) < 0 || row == grid.size() || col == grid[0].size() || visited[row][col] || grid[row][col] == 1){
            return 0;
        }
        if (row == grid.size() - 1 && col == grid[0].size() - 1){
            return 1;
        }
        int count = 0;
        visited[row][col] = 1;
        count += dfs (grid, row + 1, col, visited);
        count += dfs (grid, row - 1, col, visited);
        count += dfs (grid, row, col + 1, visited);
        count += dfs (grid, row, col - 1, visited);
        visited[row][col] = 0;
        return count;
    }
    int countPaths(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
    
        int m = grid.size();
        int n = grid[0].size();
    
        vector<vector<int>> visited(m, vector<int>(n, 0));
        return dfs(grid, 0, 0, visited);
    }
};
