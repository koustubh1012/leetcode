class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 1 && board[0].size() == 1){
            if(board[0][0] == word[0] && word.size() == 1) return true;
            else return false;
        }
        bool found = false;
        string cur;
        vector<string> words;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(found) break;
                backtrack(board, word, cur, found, 0, i, j, visited);
            }
            if(found) break;
        }
        return found;
    }
void backtrack(vector<vector<char>>& board, string word, string& cur, bool& found, int start, int i, int j, vector<vector<bool>>& visited){
    if (found) return;
    
    if ((int)start == (int)word.size()) { // matched all chars
        found = true;
        return;
    }

    if (i < 0 || j < 0 || i >= (int)board.size() || j >= (int)board[0].size() || visited[i][j] || board[i][j] != word[start]) {
        return;
    }
 
    visited[i][j] = true;
    cur.push_back(word[start]);
    
    if(i + 1 < board.size()) backtrack(board, word, cur, found, start + 1, i + 1, j, visited);
    if(i - 1 >= 0) backtrack(board, word, cur, found, start + 1, i - 1, j, visited);
    if(j + 1 < board[0].size()) backtrack(board, word, cur, found, start + 1, i, j + 1, visited);
    if(j - 1 >= 0) backtrack(board, word, cur, found, start + 1, i, j - 1, visited);

    visited[i][j] = false;
    cur.pop_back();

    return;
}
};
