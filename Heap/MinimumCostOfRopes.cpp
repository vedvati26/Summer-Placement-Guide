class Solution
{
    public:
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long> > pq(
            arr, arr + n);
    
        long long res = 0;
        while (pq.size() > 1) 
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            res += first + second;
            pq.push(first + second);
        }
        return res;
    }
};
