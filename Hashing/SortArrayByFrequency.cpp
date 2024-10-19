class Solution{
    public:
    static bool comparator(pair<int, int>& a, pair<int, int>& b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    
    vector<int> sortByFreq(int arr[],int n)
    {
        vector<int> ans;
        vector<pair<int, int>> freq_vec;
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        for(auto it: mp){
            freq_vec.push_back({it.second, it.first});
        }
        sort(freq_vec.begin(), freq_vec.end(), comparator);
        
        for(auto it: freq_vec){
            for(int i=0; i<it.first; i++){
                ans.push_back(it.second);
            }
        }
        
        return ans;
    }
};