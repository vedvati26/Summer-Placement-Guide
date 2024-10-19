class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        
        int result = 0;
        for(int i = 0; i < N; i++)
        {
            if(i % 2 == 0)
                result = result ^ A[i];
        }
        if(N % 2 == 0)
            return 0;
        else
            return result;
    }
};
