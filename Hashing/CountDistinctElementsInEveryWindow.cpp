class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        map<int,int>mp;
        for(int i=0;i<k;i++){
              mp[A[i]]++;
      }
      vector<int>vec;
      vec.push_back(mp.size());
        
      for(int i=k;i<n;i++){
             int element =A[i-k];
             mp[element]--;
             if(mp[element]==0){
                   mp.erase(element);
             }
             mp[A[i]]++;
             vec.push_back(mp.size());
      }
      return vec;
    }
};