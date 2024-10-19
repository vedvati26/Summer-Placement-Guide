class Solution
{
    public:
    int getRightMostSetBit(int n)
    {
        return log2(n & -n) + 1; 
    }

    int posOfRightMostDiffBit(int m, int n)
    {
        if(m==n)
            return -1;
        return getRightMostSetBit(m ^ n); 
    }

};
