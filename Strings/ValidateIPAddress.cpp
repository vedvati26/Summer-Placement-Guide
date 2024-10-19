class Solution {
  public:
    int isValid(string s) {
        int counter = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.')
                counter++;
        }
        if (counter != 3)
            return 0;
        unordered_set<string> st;
        for (int i = 0; i < 256; i++)
            st.insert(to_string(i));
        counter = 0;
        string temp = "";
        for (int i = 0; i < s.length(); i++) {

            if (s[i] != '.') {
                temp = temp + s[i];
            } else {
                if (st.count(temp) != 0)
                    counter++;

                temp = "";
            }
        }
        if (st.count(temp) != 0)
            counter++;

        if (counter == 4)
            return 1;
        else
            return 0;
    }
};