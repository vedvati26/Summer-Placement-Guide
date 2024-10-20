class Solution
{
    public:
    void swap(int *a,int *b)
    {
    	int c=*a;
    	*a=*b;
    	*b=c;
    }
    
    public:
    void heapify(int arr[], int n, int i)  
    {
        int l=i*2+1;
    	int r=i*2+2;
    	int largest=i;
    	if(l<n && arr[largest]<arr[l])
    		largest=l;
    	if(r<n && arr[largest]<arr[r])
    		largest=r;	
    	if(largest!=i)
    	{
    		swap(&arr[i],&arr[largest]);
    		heapify(arr,n,largest); 
    	}
    }
    
    public:
    void buildHeap(int arr[], int n) 
    { 
    	for(int i=n/2-1;i>=0;i--)
    	   heapify(arr,n,i); 
    }
    
    public:
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for (int i=n-1; i>=0; i--)
        {
            swap(&arr[0], &arr[i]);
            heapify(arr, i, 0);
        }
    }
};
