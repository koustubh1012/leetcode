class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int total_cost = 0;
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0});

        while(!minHeap.empty()){
            auto edge = minHeap.top();
            minHeap.pop();
            int point = edge.second;
            int cost = edge.first;

            if(visited.find(point) != visited.end()) continue;

            visited.insert(point);
            total_cost += cost;

            for(int i = 0; i < points.size(); i++){
                if(visited.find(i) == visited.end()){
                    int dist = get_distance(points[point], points[i]);
                    minHeap.push({dist, i});
                }
            }
        }

        return total_cost;
    }
private:
    int get_distance(vector<int>& A, vector<int>& B){
        return abs(A[0] - B[0]) + abs(A[1] - B[1]);
    }
};
