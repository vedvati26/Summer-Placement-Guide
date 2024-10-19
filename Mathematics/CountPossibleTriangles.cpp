class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr,arr+n);
        int ans = 0;
        for(int i=n-1;i>0;--i){
            int lo = 0,hi = i-1;
            while(lo<hi){
                if(arr[i]>=arr[lo]+arr[hi]){
                    lo += 1;
                }
                else{
                    ans+=hi-lo;
                    hi-=1;
                }
            }
        }
        return ans;
    }
};

