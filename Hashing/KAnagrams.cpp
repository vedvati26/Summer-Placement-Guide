class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        unordered_map<char, int> mp;
        int s1 = str1.size();
        int s2 = str2.size();
        
        if(s1 != s2)
        return false;
        
        for(int i=0; i < s1; i++)
        {
            mp[str1[i]]++;
        }
        for(int i = 0; i<s2; i++)
        {
            if(mp[str2[i]] <= 0)
            k--;
            else
            mp[str2[i]]--;
        }
        //cout<< k<<" k\n";
        if(k>=0)
        return true;
        else
        return false;
        
    }
};