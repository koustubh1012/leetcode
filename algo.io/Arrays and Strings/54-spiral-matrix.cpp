class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = 0;
        int right_wall = n;
        int down_wall = m;
        int left_wall = 0;
        int up_wall = 0;
        bool move_left = false;
        bool move_down = false;
        bool move_right = true;
        bool move_up = false;

        while (ans.size() != m * n) {
    if (move_left) {
        while (j >= left_wall) {
            ans.push_back(matrix[i][j]);
            j--;
        }
        i--;
        j++;
        down_wall--;
        move_left = false;
        move_up = true;
    }
    else if (move_down) {
        while (i < down_wall) {
            ans.push_back(matrix[i][j]);
            i++;
        }
        j--;
        i--;
        right_wall--;
        move_down = false;
        move_left = true;
    }
    else if (move_right) {
        while (j < right_wall) {
            ans.push_back(matrix[i][j]);
            j++;
        }
        i++;
        j--;
        up_wall++;
        move_right = false;
        move_down = true;
    }
    else if (move_up) {
        while (i >= up_wall) {
            ans.push_back(matrix[i][j]);
            i--;
        }
        j++;
        i++;
        left_wall++;
        move_up = false;
        move_right = true;
    }
}


        return ans;
    }
};
