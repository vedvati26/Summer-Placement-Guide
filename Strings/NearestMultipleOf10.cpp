class Solution{
    public:
    string roundToNearest(string str) 
    { 
        int n = str.size();
        if (str[n - 1] - '0' <= 5) { 
            str[n - 1] = '0'; 
            return str.substr(0, n); 
        } 
        else 
        {  
            int carry = 0; 
            str[n - 1] = '0';  
            int i = n - 2; 
            carry = 1; 
            while (i >= 0 && carry == 1) { 
                int currentDigit = str[i] - '0'; 
                currentDigit += carry;  
                if (currentDigit > 9) { 
                    carry = 1; 
                    currentDigit = 0; 
                } 
                else
                    carry = 0; 
                str[i] = (char)(currentDigit + '0'); 
                i--; 
            } 
            if (carry == 1) 
                cout << carry; 
            return str.substr(0, n); 
        } 
    }  

};