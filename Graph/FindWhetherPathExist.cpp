class Solution 
{
    public:
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1};
    bool isValid(int x, int y, int n, int m){
        return (x >= 0 and x < n and y >=0 and y < m);
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		if(grid[i][j] == 1){
        			q.push({i,j});
        		}
        	}
        }
        
        while(!q.empty())
        {
        	int x = q.front().first;
        	int y = q.front().second;
        	q.pop();
        	for(int i = 0; i < 4; i++)
        	{
        		int n_x = x + dx[i];
        		int n_y = y + dy[i];
        		if(isValid(n_x, n_y, n, m))
        		{
        			if(grid[n_x][n_y] == 2)
        				return true;
        			if(grid[n_x][n_y] == 3){
        				grid[n_x][n_y] = 1;
        				q.push({n_x, n_y});
        			}
        		}
        	}
        }
        return false;

    }
};
