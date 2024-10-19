class Solution{
public:
    int count(int N){
        // code here
        int n = N/2;
        long int dp[n+1];
        dp[0] = dp[1] = 1;
        for (int i=2; i<=n; i++)
        {
            dp[i] = 0;
            for (int j=0; j<i; j++)
                dp[i] += dp[j] * dp[i-j-1];
        }
        return dp[n];
    }
};