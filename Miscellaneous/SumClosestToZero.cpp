class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            sort(arr, arr+n);
            int i=0 , j=n-1,curr_sum;
            int sum=arr[i] + arr[j];
            
            while(i<j) {
                curr_sum = arr[i] + arr[j];
                if(abs(curr_sum) == abs(sum))
                    sum = max(curr_sum,sum);
                else if (abs(curr_sum) < abs(sum))
                    sum = curr_sum;
                
                if (curr_sum > 0)
                    j--;
                else
                    i++;
            }
            return sum;
        }
};
