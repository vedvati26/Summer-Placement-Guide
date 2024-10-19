class Solution {
  public:
  void sieve(int n,vector<bool>& prime){
        prime[0]=prime[1]=true;
        for(int i=2;i*i<=n;i++){
            if(!prime[i]){
                for(int j=2*i;j<=n;j+=i){
                    prime[j]=true;
                }
            }
        }
    }
    vector<int> primeDivision(int N) {
        // code here
        vector<bool>prime(N+1,false);
        vector<int>ans;
        sieve(N,prime);
        for(int i=2;i<=N;i++){
            if(prime[i]==false && prime[N-i]==false){
                ans.push_back(i);
                ans.push_back(N-i);
                return ans;
            }
        }
        return ans;
    }
};