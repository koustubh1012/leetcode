class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        vector<vector<int>> result;
        
        for(int i = 0; i < m; i++){
            dfs(heights, i, 0, 0, pacific);
            dfs(heights, i, n - 1, 0, atlantic);
        }
        
        for(int i = 0; i < n; i++){
            dfs(heights, 0, i, 0, pacific);
            dfs(heights, m - 1, i, 0, atlantic);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }

        return result;
    }
    void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<bool>>& visited){
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()) return;
        else if(heights[i][j] >= prev && visited[i][j] == false){
            prev = heights[i][j];
            visited[i][j] = true;
            dfs(heights, i + 1, j, prev, visited);
            dfs(heights, i - 1, j, prev, visited);
            dfs(heights, i, j + 1, prev, visited);
            dfs(heights, i, j - 1, prev, visited);
            return;
        }
        return;
    }
};
