class Solution {
  public:
    long long toh(int n, int from, int to, int aux) {
        if(n==0){
            return 0;
        }
        long long ans=1;
        ans=ans+toh(n-1,from,aux,to);
        cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
       
        ans=ans+toh(n-1,aux,to,from);
        return ans;
    }
};