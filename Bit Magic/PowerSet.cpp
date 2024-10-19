class Solution{
    public:
        vector<string> AllPossibleStrings(string s){
            vector<string>res;
	    int n = s.size();
	    for(int i = 0; i < (1 << n); i++){
		string temp ="";
		for(int j = 0; j < n; j++){
		    if(i & (1 << j))
			temp += s[j];
		}
		if(temp.size())
		res.push_back(temp);
	    }
	    sort(res.begin(), res.end());
	    return res;
        }
};
