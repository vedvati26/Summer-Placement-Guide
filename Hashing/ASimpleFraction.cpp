class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
	    string beforeDot = "";
	    
	    int newNumerator = numerator/denominator;
	    int remainder = numerator % denominator;
	    
	    if(remainder == 0) return to_string(newNumerator);
	    
	    beforeDot += to_string(newNumerator);
	    newNumerator = remainder;
	    unordered_map<int,int> mp;
	    string afterDot = "";
	    
	    while(newNumerator != 0 and mp.find(newNumerator) ==  mp.end()){
	        
	        mp[newNumerator] = afterDot.length();
	        newNumerator *= 10;
	        afterDot += to_string(newNumerator/denominator);
	        newNumerator %= denominator;
	        
	    }
	    
	    if(newNumerator == 0){
	        return beforeDot + "." +   afterDot ;
	    }
	    
	    afterDot.insert(mp[newNumerator], "(");
	    afterDot += ")";
	    return beforeDot + "." + afterDot;
	}
};