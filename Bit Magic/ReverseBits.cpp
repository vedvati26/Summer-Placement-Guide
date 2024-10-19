class Solution {
  public:
    long long reversedBits(long long x) {
        
        if(x==0)
            return 0;
        string s = bitset<32>(x).to_string(); 
        s = s.substr(s.find('1'));
        
        long long y = 32 - s.length();
        
        s = string(y, '0') + s;
        
        // Reverse the binary
        reverse(s.begin(), s.end());
    
        long long ans = bitset<32>(s).to_ulong(); 
        return ans;
    }
};
