class Solution {
   public:
    //Function to find all possible unique subsets.
    void solve(int indx , vector<int>&arr , vector<int>&res , vector<vector<int>>&ans){
        ans.push_back(res) ; 
        for(int i=indx;i<arr.size();i++){
            if(i != indx && arr[i] == arr[i-1]){
                continue ; 
            }res.push_back(arr[i]) ; 
            solve(i+1 , arr , res , ans) ; 
            res.pop_back() ; 
        }
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int>>ans ; 
        sort(arr.begin() , arr.end()) ;   
        vector<int>res ; 
        solve(0 , arr , res , ans) ; 
        return ans ; 
    }

};