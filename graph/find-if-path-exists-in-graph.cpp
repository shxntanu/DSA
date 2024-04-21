class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // adjacency list representation for a graph
        unordered_map<int, vector<int>> graph;
        for(const auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        unordered_set<int> visited;
        return dfs(source, destination, graph, visited);
    }

    bool dfs(int node, int dst, unordered_map<int, vector<int>>&graph, unordered_set<int>&visited) {
        // if source node == dst node, path exists
        if(node == dst) return true;
        // mark current node as visited
        visited.insert(node);
        //iterate thru neighbours of current node
        for(int neighbour : graph[node]) {
            // if neighbour has not yet been visited, visit it
            if(visited.find(neighbour) == visited.end()) {
                if(dfs(neighbour, dst, graph, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
