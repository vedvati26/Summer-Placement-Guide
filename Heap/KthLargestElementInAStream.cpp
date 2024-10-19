class Solution
{
    public:
    void kthLargest(int arr[], int N, int k)
    {
    	priority_queue<int,vector<int>,greater<int>> pq; 
    	
    	for(int i=0;i<N;i++)
    	{
    	    if(pq.size() < k) 
    			pq.push(arr[i]);
    		else 
    		{
    			if(arr[i] > pq.top()) 
    			{
    				pq.pop();
    				pq.push(arr[i]);
    			}
    		}
    		if(pq.size()<k)
    			cout<<-1<<" ";
    		else
    			cout<<pq.top()<<" "; 
    	}
    }
};
