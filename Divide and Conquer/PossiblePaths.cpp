class Solution {
  public:
  int M=1e9+7;
   int dfs(int u,int v, vector<int>adj[],int k,vector<vector<int>>&dp){
       if(u==v && k==0){
           
           return 1;
       }
       if(k==0&&u!=v){
           return 0;
       }
       int ans=0;
       if(dp[u][k]!=-1)return dp[u][k];
       for(auto & e : adj[u]){
           ans=ans+dfs(e,v,adj,k-1,dp);
           ans=ans%M;
       }
       return dp[u][k]=ans;
       
   }
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    vector<int>adj[graph.size()];
	    for(int i=0;i<graph.size();i++){
	        for(int j=0;j<graph[i].size();j++){
	            if(graph[i][j]==1)
	            adj[i].push_back(j);
	        }
	    }
	    vector<vector<int>>dp(graph.size(),vector<int>(k+1,-1));
	    
	    return dfs(u,v,adj,k,dp);
	    
	    
	}

};