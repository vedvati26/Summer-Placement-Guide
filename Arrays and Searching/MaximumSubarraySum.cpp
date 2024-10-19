int maxSubArray(vector<int> nums) {
        int n = nums.size();
        
        int m_sum=nums[0], curr=nums[0];
        
        for(int i = 1 ; i< n ; ++ i ) {
            
            if(nums[i]>nums[i]+curr)
                curr = nums[i];
            else
                curr+=nums[i];
            m_sum=max(m_sum,curr);
        }
        return m_sum;
    }