class Solution{
public:
    long long int optimalKeys(int N){
        if(N <= 6)
            return (unsigned long long int)N;
        long long int screen[N+1], j, i;
        for(i = 1;i <= 6;i++)
            screen[i-1] = i;
        for(i = 7;i <= N;i++){
            screen[i-1] = 0;
            for(j = i-3;j >= 1;j--){
                long long int cur = (i-j-1)*screen[j-1];
                if(cur > screen[i-1])
                    screen[i-1] = cur;
            }
        }
        return screen[N-1];
    }
};
