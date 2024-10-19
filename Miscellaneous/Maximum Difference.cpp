class Solution {
  public:
   int findMaxDiff(const vector<int> &arr, int n) {
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    stack<int> q;
    
    // Finding nearest smaller element to the left
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.top() >= arr[i]) {
            q.pop();
        }
        if (!q.empty()) {
            left[i] = q.top();
        }
        q.push(arr[i]);
    }

    // Clearing the stack for reuse
    while (!q.empty()) {
        q.pop();
    }

    // Finding nearest smaller element to the right
    for (int i = n - 1; i >= 0; i--) {
        while (!q.empty() && q.top() >= arr[i]) {
            q.pop();
        }
        if (!q.empty()) {
            right[i] = q.top();
        }
        q.push(arr[i]);
    }

    // Calculating maximum difference
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int z = abs(left[i] - right[i]);
        maxi = max(maxi, z);
    }

    return maxi;
}
};