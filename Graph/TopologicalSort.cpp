class Solution
{
	public:
	void topo(vector<int> adj[], int u, bool visited[], stack<int> &s) 
	{
        visited[u] = true;
        for (auto v : adj[u])
        {
            if (!visited[v])
                topo(adj, v, visited,s); 
        }
        s.push(u); 
    } 
    vector <int> topoSort(int N, vector<int> adj[]) 
    {
        bool visited[N+1];                
        memset(visited, 0, sizeof visited); 
        
        stack<int> s;
        for (int i = 0; i < N; i++) 
        {
            if (!visited[i])              
                topo(adj, i, visited, s); 
        }
    
        vector <int> res;
        int i = -1;
        while (!s.empty())
        {
            res.push_back (s.top()); 
            s.pop();
        }
        return res;
    }
};
