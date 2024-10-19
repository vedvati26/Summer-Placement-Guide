class Solution
{
	public:
	int minDistance(vector <int> &dist, bool sptSet[],int V)
    {
        int min = INT_MAX, min_index;
        
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        
        return min_index;
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<vector<int> > adj_mat(V, vector<int>(V, 0));
        for(int i=0; i<V; i++)
            for(int j=0; j<adj[i].size(); j++)
                adj_mat[i][adj[i][j][0]] = adj[i][j][1];
        vector <int> dist(V);
        bool sptSet[V];
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;
        dist[S] = 0;
        for (int count = 0; count < V-1; count++)
        {
            int u = minDistance(dist, sptSet,V);
            sptSet[u] = true;
            for (int v = 0; v < V; v++)
            {
                if (!sptSet[v] && adj_mat[u][v] && dist[u] != INT_MAX 
                                            && dist[u]+adj_mat[u][v] < dist[v])
                    dist[v] = dist[u] + adj_mat[u][v];
            }
        }
        return dist;
    }
};
