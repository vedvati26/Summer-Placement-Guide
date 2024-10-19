class Solution {
public:
    int dp[101][10001];

    int solve(vector<int>& nums, int n, int i, int amount)
    {

        if (amount < 0) {
            return (int)(1e9);
        }

        if (i >= n) {
            if (amount == 0) {
                return 0;
            }
            return (int)(1e9);
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int ans1 = solve(nums, n, i + 1, amount);
        int ans2 = 1 + solve(nums, n, i, amount - nums[i]);

        return dp[i][amount] = min(ans1, ans2);
    }

    int MinCoin(vector<int> nums, int amount)
    {
        memset(dp, -1, sizeof(dp));

        int ans = solve(nums, nums.size(), 0, amount);

        if (ans >= (int)(1e9)) {
            return -1;
        }
        else {
            return ans;
        }
    }
};
