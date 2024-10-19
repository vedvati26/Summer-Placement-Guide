class Solution{
public:
    int fib(int N){
        // if N is equal to zero then return 0
        if(N == 0)
            return 0;
        // if N is equal to 1 then return 1
        else if(N == 1)
            return 1;
        int a = 0;
        int b = 1;
        // calculate the Nth fib number's last digit
        for(int i = 2;i<=N;i++)
        {
            // Mod by 10 because we only need last digit
            int c = b%10;
            b=(a+b)%10;
            a=c%10;
        }
        // return the Nth digit last number
        return b;
    }
};