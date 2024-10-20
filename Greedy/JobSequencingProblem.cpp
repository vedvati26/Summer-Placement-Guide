class Solution 
{
    public:
    bool static cmp(Job a, Job b){
        return a.dead < b.dead;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    {
        sort(arr, arr+n, cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        int curr = 1;
        
        for(int i = 0; i < n; i++){
            if(arr[i].dead >= curr){
                pq.push(arr[i].profit);
                curr++;
            }else {
                if(arr[i].profit > pq.top()){
                    pq.push(arr[i].profit);
                    pq.pop();
                }
            }
        }
        
        int total = 0;
        int job = pq.size();
        
        while(!pq.empty()){
            total += pq.top();
            pq.pop();
        }
        return {job, total};
    } 
};
