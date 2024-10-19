class Solution 
{
    public:
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int, int>> nums2;
        for(int i=0; i<nums.size(); i++)
        {
            nums2.push_back(make_pair(nums[i], i));
        }
        sort(nums2.begin(), nums2.end());
        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums2[i].second==i)
            {
                continue;
            }
            else
            {
                swap(nums2[i], nums2[nums2[i].second]);
                i--;
                ans++;
            }
        }
        return ans;   
	}
};