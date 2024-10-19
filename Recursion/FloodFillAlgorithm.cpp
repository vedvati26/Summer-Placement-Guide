class Solution {
    private:
    
    void DFS(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, 
    int newColor, int delRow[], int delCol[], int initialColor){
        
        ans[row][col] = newColor;
        
        int n = image.size();
        int m = image[0].size();
        
        for(int i = 0; i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow>=0 && nrow< n && ncol >=0 && ncol < m 
            && image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor){
                
                DFS(nrow,ncol,ans,image,newColor,delRow,delCol,initialColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int initialColor = image[sr][sc];
        
        vector<vector<int>> ans = image;
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        DFS(sr,sc,ans,image,newColor,delRow, delCol, initialColor);
        
        return ans;
    }
};