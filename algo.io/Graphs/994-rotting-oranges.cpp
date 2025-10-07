class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> rotten_queue;
        int fresh_count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    rotten_queue.push(make_pair(i,j));
                }
                if(grid[i][j] == 1){
                    fresh_count++;
                }
            }
        }

        if(fresh_count == 0) return 0;

        int minute = 0;

        while(!rotten_queue.empty()){

            bool is_rotten = false;

            int q_size = rotten_queue.size();

            for(int k = 0; k < q_size; k++){
                auto coord = rotten_queue.front();
                rotten_queue.pop();
                int i = coord.first;
                int j = coord.second;

                if(i+1 < m){
                    if(grid[i+1][j] == 1){
                        grid[i+1][j] = 2;
                        rotten_queue.push(make_pair(i+1, j));
                        fresh_count--;
                        is_rotten = true;
                    }
                }
                if(i-1 >= 0){
                    if(grid[i-1][j] == 1){
                        grid[i-1][j] = 2;
                        rotten_queue.push(make_pair(i-1, j));
                        fresh_count--;
                        is_rotten = true;
                    }
                }
                if(j+1 < n){
                    if(grid[i][j+1] == 1){
                        grid[i][j+1] = 2;
                        rotten_queue.push(make_pair(i, j+1));
                        fresh_count--;
                        is_rotten = true;
                    }
                }
                if(j-1 >= 0){
                    if(grid[i][j-1] == 1){
                        grid[i][j-1] = 2;
                        rotten_queue.push(make_pair(i, j-1));
                        fresh_count--;
                        is_rotten = true;
                    }
                }
            }
            if(is_rotten) minute++;
        }
        return fresh_count == 0 ? minute : -1;
    }
};
