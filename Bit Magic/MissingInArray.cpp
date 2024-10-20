class Solution {
  public:
    int missingNumber(int n, vector<int>& arr) {
        long long total = (n + 1) * (n) / 2;
        for (int i = 0; i < n - 1; i++)
            total -= arr[i];
        return (int)total;
    }
};
