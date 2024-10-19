class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n = s.size();
        int m = t.size();
        vector<vector<int>> ans(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++)ans[i][0]=i;
        for(int j=0;j<=m;j++)ans[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    ans[i][j]=ans[i-1][j-1];
                }else{
                    ans[i][j]=min(ans[i-1][j-1],min(ans[i-1][j],ans[i][j-1]))+1;
                }
            }
        }
        return ans[n][m];
    }
};