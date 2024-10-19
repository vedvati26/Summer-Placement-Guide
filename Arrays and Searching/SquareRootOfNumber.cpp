class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        int l=0, r = x, ans = 0;
        
        while( l<=r ){
            long long int mid = l + (r-l)/2;
            
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid < x){
                ans = mid;
                l = mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};