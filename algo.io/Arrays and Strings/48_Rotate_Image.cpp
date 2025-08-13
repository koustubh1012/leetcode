class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // get the size of the matrix
        int n = matrix.size();

        //martrix tranpose
        for (int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // matrix horizontal reflection
        for (int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
