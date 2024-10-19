class Solution {
public:
    int maxSubsetXOR(int arr[], int N) {
        if (N == 0) return 0;
        int result = 0;
        while (true) {
            int maxElement = *max_element(arr, arr + N);
            if (maxElement == 0) return result;
            result = max(result, result ^ maxElement);
            for (int i = 0; i < N; ++i) {
                arr[i] = min(arr[i], arr[i] ^ maxElement);
            }
        }
        return result;
    }
};