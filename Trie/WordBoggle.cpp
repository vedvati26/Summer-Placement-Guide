class Solution {
public:
bool dfs(int i,int j,vector<vector<char> >& board,string a,int k,int n,int m)
{
    if(k==a.size())return true;
    if(i<0||j<0||i>=n||j>=m||board[i][j]!=a[k])return false;
    
    int ans=false;
    char temp=board[i][j];
    board[i][j]=' ';
    int nrow[]={-1,0,1,0,1,1,-1,-1};
    int ncol[]={0,1,0,-1,1,-1,1,-1};
    
    for(int l=0;l<8;l++)
    {
        int row=i+nrow[l];
        int col=j+ncol[l];
        
        ans=ans|dfs(row,col,board,a,k+1,n,m);
    }
    board[i][j]=temp;
    
    return ans;
}
    vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& d){
        vector<string> ans;
        int n=board.size();
        int m=board[0].size();
        for(auto i:d)
        {
            int f=0;
            for(int j=0;j<n;j++)
            {
                for(int l=0;l<m;l++)
                {
                    if(i[0]==board[j][l])
                    {
                        if(dfs(j,l,board,i,0,n,m))
                        {
                            ans.push_back(i);
                            f=1;
                            break;
                        }
                    }
                }
                if(f)break;
            }
        }
       // cout<<dfs(0,0,board,d[0],0,n,m)<<endl;
        return ans;
    }
};