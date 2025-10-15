class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lower_row = 0;
        int upper_row = m - 1;

        while(lower_row <= upper_row){
            int mid_row = (lower_row + upper_row) / 2;
            if(target >= matrix[mid_row][0] && target<= matrix[mid_row][n-1]){
                int lower_col = 0;
                int upper_col = n - 1;
                while(lower_col <= upper_col){
                    int mid_col = (upper_col + lower_col) / 2;
                    if(target == matrix[mid_row][mid_col]){
                        return true;
                    }
                    else if(target > matrix[mid_row][mid_col]){
                        lower_col = mid_col + 1;
                    }
                    else{
                        upper_col = mid_col - 1;
                    }
                }
                return false;
            }
            else if(target < matrix[mid_row][0]){
                upper_row = mid_row - 1;
            }
            else{
                lower_row = mid_row + 1;
            }
        }
        return false;
    }
};
