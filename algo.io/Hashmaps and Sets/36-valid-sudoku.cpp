class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_set<char> row;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(row.find(board[i][j]) != row.end()) return false;
                    row.insert(board[i][j]);
                }
            }
        }

        for(int i = 0; i < 9; i++){
            unordered_set<char> column;
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    if(column.find(board[j][i]) != column.end()) return false;
                    column.insert(board[j][i]);
                }
            }
        }

        vector<vector<int>> starts = {{0, 0}, {0, 3}, {0, 6},
                                      {3, 0}, {3, 3}, {3, 6},
                                      {6, 0}, {6, 3}, {6, 6}};
        
        for (auto& start : starts) {
            unordered_set<char> set;
            for (int row = start[0]; row < start[0] + 3; row++) {
                for (int col = start[1]; col < start[1] + 3; col++) {
                    char item = board[row][col];
                    if (item != '.' && !set.insert(item).second) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
