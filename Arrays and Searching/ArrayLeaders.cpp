class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int n, int arr[]){
        // Code here
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int j;
            for (j = i+1; j < n; j++)
            {
                if (arr[i] < arr[j])
                    break;
            }   
            if (j == n) // the loop didn't break
                ans.push_back(arr[i]);
       }
        return ans;
    }
};
