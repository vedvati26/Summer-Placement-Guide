class Solution {
  public:
    string oddEven(string s) {
        int x = 0, y = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            int count = 0;

            for (char c : s) {
                if (c == ch) {
                    count++;
                }
            }

            int position = ch - 'a' + 1;

            if (count > 0) {
                if (position % 2 == 0 && count % 2 == 0) {
                    x++;
                } else if (position % 2 != 0 && count % 2 != 0) {
                    y++;
                }
            }
        }

        if ((x + y) % 2 == 0) {
            return "EVEN";
        } else {
            return "ODD";
        }
    }
};
