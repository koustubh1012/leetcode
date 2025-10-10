class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(int i = 0; i < points.size(); i++){
            auto dist = calculate_distance(points[i]);
            minHeap.push({dist, i});
        }

        for(int i = 0; i < k; i++){
            ans.push_back(points[minHeap.top().second]);
            minHeap.pop();
        }
        
        return ans;
    }

private:
    int calculate_distance(vector<int>& A){
        return A[0]*A[0] + A[1]*A[1];
    }
};
