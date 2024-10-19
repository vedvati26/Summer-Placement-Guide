class Solution
{
    private:
    void solve(int a[],int n,string output,int i,vector<string> &ans,string mapping[]) {
        if (i==n) {
            ans.push_back(output);
            return;
        } 
        int num=a[i];
        string value=mapping[num];
        for (int j=0;j<value.length();j++) {
            output.push_back(value[j]);
            solve(a,n,output,i+1,ans,mapping);
            output.pop_back();
        }
    }
    public:
    vector<string> possibleWords(int a[], int n) {
        vector <string> ans;
        if (n==0) return ans;
        string output;
        int i=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(a,n,output,i,ans,mapping);
        return ans;
    }
};