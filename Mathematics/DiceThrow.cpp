class Solution {
  public:
    long long solve(int M, int N, int target, int attempt, vector<vector<long long>>& dp) {
    // Base cases
    if (target == 0 && attempt == N) {
        return 1;
    }
    if (target == 0 || attempt == N) {
        return 0;
    }
    if (dp[target][attempt] != -1) {
        return dp[target][attempt];
    }
    
    long long ways = 0;
    for (int i = 1; i <= M && target - i >= 0; ++i) {
        ways += solve(M, N, target - i, attempt + 1, dp);
    }
    
    dp[target][attempt] = ways;
    return ways;
}

long long noOfWays(int M, int N, int X) {
    // Initialize dp table with -1
    vector<vector<long long>> dp(X + 1, vector<long long>(N + 1, -1));
    return solve(M, N, X, 0, dp);
}
};