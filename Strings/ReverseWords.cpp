class Solution
{
    public:
    string reverseWords(string s) 
    { 
        string result = "";
        string curr_word = "";
        vector<string> words;
        for (int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '.')
            {
                words.push_back(curr_word);
                curr_word = "";
            }
            else
                curr_word += s[i];
        }
        words.push_back(curr_word);
        for (int i = words.size()-1; i>=0; --i)
        {
            result += words[i];
            if(i!=0)
                result += '.';
        }
        return result;
    } 
};
