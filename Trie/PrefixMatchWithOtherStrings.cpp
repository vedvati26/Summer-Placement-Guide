class Solution {   
public:
    bool isPrefix(string prefix, string str) {
        if(prefix.size() > str.size()) return false;
        for(int i=0; i<prefix.size(); i++) {
            if(prefix[i]!=str[i]) return false;
        }
        return true;
    }
    int klengthpref(string arr[], int n, int k, string str){    
        if(k>str.size()) return 0;
        
        int count {};
        string prefix = str.substr(0,k);
        for(int i=0; i<n; i++) {
            if(isPrefix(prefix, arr[i])) {
                count++;
            }
        }
        return count;
    }
};