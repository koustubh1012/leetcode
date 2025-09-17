class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> seen;
        seen.insert(source);
        return dfs(graph, source, destination, seen);
    }

    bool dfs(unordered_map<int, vector<int>>& graph, int source, int destination, unordered_set<int>& seen){
        if(source == destination) return true;
        for(auto edge : graph[source]){
            if(seen.find(edge) == seen.end()){
                seen.insert(edge);
                if(dfs(graph, edge, destination, seen)) return true;
            }
        }
        return false;
    }
};
