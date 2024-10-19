/*class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        if(n <= 1) return 1;
        int s1 = 1;
        int s2 = 1;
        
        for(int i = 2; i <= n; i++) {
            int s = (s1 + s2) % 1000000007;
            s1 = s2;
            s2 = s;
        }
        return s2;
        // your code here
    }
};*/
class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        long long res[n + 1];

        // base cases
        res[0] = 1;
        res[1] = 1;

        // storing number of ways to reach the ith index as
        // number of ways to reach (i-2)th index +1.
        for (int i = 2; i <= n; i++)
            res[i] = (res[i - 2] + 1);

        // returning the result.
        return res[n];
    }
};

