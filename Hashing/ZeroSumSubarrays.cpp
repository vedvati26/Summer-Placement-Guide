class Solution{
public:
    long long int findSubarray(vector<long long int> &arr, int n ) {
        long long ans=0, zero=0, presum=0;

        unordered_map<long long, long long>mpp;

        for(int i=0;i<n;i++){

            presum+=arr[i];
            if(presum==0) ans++;
            mpp[presum]++;

        }

        for(auto it:mpp) {

            long long x=it.second;
            ans+= (x*(x-1))/2;

        }
        return ans;
    }
};