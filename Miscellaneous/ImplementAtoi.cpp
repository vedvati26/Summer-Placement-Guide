class Solution{
  public:
    int atoi(string s) {
         int neg=1;
         int i=0;
        if(s[0]=='-')
        {
            i++; 
        neg=-1;
            
        }
        
        int ans=0;
        for(i;i<s.size();i++)
        {
            if( s[i]<='9' and s[i]>='0')
            ans=ans*10+s[i]-48;
            else
            return -1;
        }
        return ans*neg;
    }
};