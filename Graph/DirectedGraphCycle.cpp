class Solution {
  private:
    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack,
                      vector<int> adj[]) {
        if (visited[v] == false) {
            visited[v] = true;
            recStack[v] = true;
            for (int i = 0; i < (int)adj[v].size(); ++i) {
                if (!visited[adj[v][i]] &&
                    isCyclicUtil(adj[v][i], visited, recStack, adj))
                    return true;
                else if (recStack[adj[v][i]])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }

  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        for (int i = 0; i < V; i++)
            if (isCyclicUtil(i, visited, recStack, adj)) return true;

        return false;
    }
};
