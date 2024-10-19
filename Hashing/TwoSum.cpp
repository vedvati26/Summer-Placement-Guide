class Solution
{
    public:
    bool keypair(vector<int> array, int n, int x)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int target = x - array[i];

        if (mp.find(target) != mp.end())
            return 1;
        if (mp.find(array[i]) == mp.end()) 
            mp[array[i]] = i;
        
    }
    return 0;
}
};