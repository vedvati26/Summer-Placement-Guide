class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> dict, string pattern) {
        // code here
        
        vector<string> ans;
        for(int i=0;i<dict.size();i++)
        {
            string word=dict[i];
            string caps;
            
            for(int j=0;j<word.length();j++)
            {
                if(isupper(word[j]))
                {
                    caps+=word[j];
                }
                
                
                 
            if(caps==pattern)
            {
                ans.push_back(word);
                break;
            }
            }
        }
        if(ans.size()!=0)
        {
            return ans;
        }else
        {
            ans.push_back("-1");
            return ans;
        }
        
    }
};