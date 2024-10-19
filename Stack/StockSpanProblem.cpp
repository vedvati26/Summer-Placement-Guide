class Solution
{
    public:
    vector <int> calculateSpan(int *price, int n)
    {
        stack<int> s;
        s.push(0);
        vector <int> S (n);
        S[0] =1;
        
        for(int i=1;i<n;i++)
        {
            while(s.empty()==false and price[s.top()] <= price[i])
                s.pop();
            int span = (s.empty()) ? (i+1) : (i-s.top());
            S[i] = span;
            s.push(i);
       	}
       	return S;
    }
};
 
