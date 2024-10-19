class Solution {
  public:
    int kth(vector<int>& arr1, vector<int>& arr2, int s1, int e1, int s2, int e2,
            int k) {
        if (s1 == e1)
            return arr2[s2 + k];
        if (s2 == e2)
            return arr1[s1 + k];
        int m1 = (e1 - s1) / 2;
        int m2 = (e2 - s2) / 2;
        if (m1 + m2 < k) {
            if (arr1[s1 + m1] > arr2[s2 + m2])
                return kth(arr1, arr2, s1, e1, s2 + m2 + 1, e2, k - m2 - 1);
            else
                return kth(arr1, arr2, s1 + m1 + 1, e1, s2, e2, k - m1 - 1);
        } else {
            if (arr1[s1 + m1] > arr2[s2 + m2])
                return kth(arr1, arr2, s1, s1 + m1, s2, e2, k);
            else
                return kth(arr1, arr2, s1, e1, s2, s2 + m2, k);
        }
    }
    int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
        int nn = arr1.size();
        int mm = arr2.size();
        return kth(arr1, arr2, 0, nn, 0, mm, k - 1);
    }
};
