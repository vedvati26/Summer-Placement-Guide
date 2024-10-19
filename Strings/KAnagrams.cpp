class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k)
    {
        int n = str1.length();
        if (str2.length() != n)
            return false;
        int hash_str1[26] = {0};
        for (int i = 0; i < n ; i++)
            hash_str1[str1[i]-'a']++;
        int count = 0;
        for (int i = 0; i < n ; i++)
        {
            if (hash_str1[str2[i]-'a'] > 0)
                hash_str1[str2[i]-'a']--;
            else
                count++;
            if (count > k)
                return false;
        }
        return true;
    }
};