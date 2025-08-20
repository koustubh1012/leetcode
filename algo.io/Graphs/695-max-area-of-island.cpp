class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // get the size of the island
        m = grid.size();
        n = grid[0].size();
        int max_area = 0;

        // iterate through the cells
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // check if the number is 1
                if(grid[i][j] == 1){
                    // perform dfs and return area
                    max_area = max(dfs(grid, i, j), max_area);
                }
            }
        }
        // at the end, return the max area from dfs
        return max_area;
    }
private:
    int m;
    int n;

    // function to perform dfs
    int dfs(vector<vector<int>>& grid, int i, int j){
        // check if the current cell is out of bounds or is water
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j]!=1){
            return 0;
        }
        grid[i][j] = 0;
        // perfrom iterative dfs
        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i , j + 1) + dfs(grid, i , j - 1);
    }
};
