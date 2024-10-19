class Solution{
    public:
    const int mod = 1000000007;
    long long power(int N,int R)
    {
       //Your code here
       if(R==0) return 1;
       
        long long ans=power(N,R/2);
        long long sq=(ans*ans)%mod;
        if(R%2==0) return sq;
        else return ((N*sq)%mod);
    }

};