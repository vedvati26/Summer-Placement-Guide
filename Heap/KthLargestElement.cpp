class Solution
{
    public:
    int KthLargest(int arr[], int n, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) 
        {
            if (pq.size() == k && pq.top() < arr[i]) 
            { 
                pq.pop();
                pq.push(arr[i]);
            }
            else if (pq.size() < k)
                pq.push(arr[i]);
        }
        return pq.top(); 
    }
};
