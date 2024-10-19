class Solution {
  public:
    static bool cmp(Item a, Item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }

  public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, cmp);
        int curWeight = 0;
        double finalvalue = 0.0;
        for (int i = 0; i < n; i++) {
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else {
                int remain = W - curWeight;
                finalvalue += arr[i].value * ((double)remain / arr[i].weight);
                break;
            }
        }
        return finalvalue;
    }
};
