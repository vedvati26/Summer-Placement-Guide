class Solution
{
    public:
    vector<long long> printFibb(int n) 
    {
        vector<long long> ans;
        long long int a=1,b=1;
        if(n>=1)
            ans.push_back(1);
        if(n>=2) 
            ans.push_back(1);
            
        
        for(int i = 2 ; i < n ; ++ i ) 
        {
            ans.push_back(a+b);
            long long int c=a+b;
            a=b;
            b=c;
        }
        return ans;
    }
};
