class Solution{
public:
    vector<int> longestCommonPrefix(string str1, string str2){
        int n=str1.length();
        int k=n;
        int flag=0;
        while(k>=0)
        {    
            string s=str1.substr(0,k);
            int pos=str2.find(s);
            if(str2.find(s)>0 && str2.find(s)<n)
            {   
                flag=1;
                int i=0;
                while(str1[i]!=s[0])
                {
                    i++;
                }
                vector<int> ans(2,-1);
                ans[0]=i;
                ans[1]=i+s.size()-1;
                
                return ans;
                break;
            }
            else
            {
                k--;
            }   
        }
        if(flag==0)
        {
            vector<int> ans(2,-1);
            return ans;
        }
    }
};