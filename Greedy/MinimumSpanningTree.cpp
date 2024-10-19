class Solution{
	public:
	
	vector<int> parent, rank;

    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) 
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b) 
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<vector<int>> res;
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<adj[i].size(); j++)
            {
                vector<int> x = adj[i][j];
                temp.push_back(x[1]);
                temp.push_back(min(i,x[0]));
                temp.push_back(max(i,x[0]));
                res.push_back(temp);
                temp.clear();
            }
        }
        sort(res.begin(), res.end());
            
        vector<vector<int>> graph;
        for(int i=0; i<res.size(); i+=2)
            graph.push_back(res[i]);
            
        int cost = 0;
        parent.resize(V);
        rank.resize(V);
        for (int i=0; i<V; i++)
            make_set(i);
        
        
        for (vector<int> e : graph)
        {
            if (find_set(e[1]) != find_set(e[2])) {
                cost += e[0];
                union_sets(e[1], e[2]);
            }
        }
        return cost;
    }
};