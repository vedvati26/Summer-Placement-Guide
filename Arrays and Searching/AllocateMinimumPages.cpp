class Solution {
  public:
  int calc(int mid,int nums[],int n)
     {
        int sum=0,count=1;
        for(int i=0;i<n;i++)
        {
              if(sum+nums[i]<=mid)
              {
                sum+=nums[i];
              }
              else
              {
                sum=nums[i];
                count++;
              }
        }
        return count;
    }
    long long findPages(int n, int arr[], int m) {
        int low=*max_element(arr,arr+n),high=accumulate(arr,arr+n,0);
         if(n<m)
        return -1;
         while(low<=high)
        {
            int mid=(low+high)/2;
            int stu=calc(mid,arr,n);
            if(stu<=m)
            {
                high=mid-1;
            }
            else 
            {
                low=mid+1;
            }

        }
        return low;
    }
};