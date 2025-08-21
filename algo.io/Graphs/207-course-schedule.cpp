class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create graph
        unordered_map<int, vector<int>> graph;
        for(vector<int> subs : prerequisites){
            graph[subs[0]].push_back(subs[1]);
        }
        
        // cretae state vector
        vector<int> states(numCourses, 0);
        // 0 = Unvisited
        // 1 = Visiting
        // 2 = Visited

        // iterate through courses marking status as you visit
        for(int i = 0; i < numCourses; i++){
            if(!dfs(graph, i, states)) return false;
        }
        return true;
    }
private:
    // dfs
    bool dfs(unordered_map<int, vector<int>> &graph, int node, vector<int> &states){
        // if visiting return false
        if(states[node] == 1) return false;
        // if visited return true
        if(states[node] == 2) return true;

        states[node] = 1;

        for(int subject : graph[node]){
            if(!dfs(graph, subject, states)){
                return false;
            }
        }

        // mark node as visited
        states[node] = 2;

        return true;
    }
};
