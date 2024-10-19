class Solution{
  public:
    int SubsequenceLength (string s) 
    {
        if (s.length() == 0 )
                return 0;
    
        int count = 1; 
        int answer = 1;
        vector<int> visited (256,-1);
        visited[s[0]]=0;
        for(int end=1; end<s.length(); end++)
        {
            int idx = s[end];
            if(visited[idx] == -1 || end-count > visited[idx])
                count++;
            else
            {
                answer = max(count, answer);
                count = end - visited[idx];
            }
            visited[idx]=end;
        }
        return max(count,answer);
    }
};