class Solution {
  public:
    void remove_util(string &str, int n) {
        int len = str.length();
        int k = 0;

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && str[i] == str[i + 1]) {
                while (i < n - 1 && str[i] == str[i + 1]) {
                    i++;
                }
            } else {
                str[k++] = str[i];
            }
        }
        str.erase(k);
        if (k != n)
            remove_util(str, k);
    }

    string rremove(string s) {
        remove_util(s, s.length());
        return s;
    }
};
