class Solution {
  public:
    long long karatsubaAlgo(string A, string B) {
        long long int t1=0;
        int c=0;
        for(int i=A.size()-1;i>=0;i--){
            t1=t1+(pow(2,c)*(A[i]-'0'));
            c++;
        }
        long long int t2=0;
        c=0;
        for(int i=B.size()-1;i>=0;i--){
            t2=t2+(pow(2,c)*(B[i]-'0'));
            c++;
        }
        return(t1*t2);
    }
};