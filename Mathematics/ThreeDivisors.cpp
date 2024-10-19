class Solution
{
public:
bool isprime(int n)
{
    if(n==1)
    return false;
    else if(n==2 || n==3)
    return true;
    else if(n%2==0 || n%3==0)
    return false;
    else{
        for(int i=5;i*i<=n;i+=6)
        {
            if(n%i==0 || n%(i+2)==0)
            return false;
        }
        return true;
    }
}
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        vector<int>v;
        // Write your code here
        for(int i=0;i<q;i++)
        {
            int bound=query[i];
            int count=0;
            for(int j=2;j<=bound;j++)
            {
                int sq=sqrt(j);
                if((sq*sq)==j & isprime(sq))
                count++;
            }
            v.push_back(count);
        }
        return v;
    }
};