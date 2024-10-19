class Solution{

    public:
    long long trappingWater(int arr[], int n){
        
        int leftmax=0;
        int rightmax=0;
        int l=0;
        int r=n-1;
        long long ans=0;
        while(l<r){
            if(arr[l]>leftmax){
                leftmax=max(leftmax,arr[l]);
            }
             if(arr[r]>rightmax){
                rightmax=max(rightmax,arr[r]);
            }
            if(leftmax<rightmax){
                ans=ans+leftmax-arr[l];
                l++;
            }
            else{
                ans=ans+rightmax-arr[r];
                r--;
            }
        }
        return ans;
    }
};