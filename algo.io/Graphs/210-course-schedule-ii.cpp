class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // cretae graph
        unordered_map<int, vector<int>> graph;
        for(vector<int> course_comb : prerequisites){
            graph[course_comb[0]].push_back(course_comb[1]);
        }

        // initialise states
        vector<int> states(numCourses, 0);

        // initalise order
        vector<int> order;

        // iterate thrrough subjects 
        for(int i = 0; i < numCourses; i++){
            // apply dfs until a cycle is dtected
            if(!dfs(graph, states, i, order)) return vector<int>{};
        }

        // return order
        return order;
    }

private:
    // dfs
    bool dfs(unordered_map<int, vector<int>> &graph, vector<int> &states, int node, vector<int> &order){

        // check if the node is already visited
        if(states[node] == 2) return true;
        if(states[node] == 1) return false;

        // mark the current node as visiting
        states[node] = 1;

        // apply dfs to discover neighbour nodes retrun false if a cycle is detected
        for (int sub : graph[node]){
            if(!dfs(graph, states, sub, order)) return false;
        } 

        // mark current node as visited
        states[node] = 2;

        //append the node in order
        order.push_back(node);

        return true;
    }
};
