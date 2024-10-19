class Solution{
  public:
    string multiplyStrings(string num1, string num2) 
    {
       int nn=1,mm=1;  
      if(num1[0]=='-')
          { nn=-1; }
      if(num2[0]=='-')
          { mm=-1; }
      
        int mul= nn*mm;
        int n1 = num1.size();
        int n2 = num2.size();
        if (n1 == 0 || n2 == 0)     return "0";
        vector<int> result(n1 + n2, 0);

        int i_n1 = 0;
        int i_n2 = 0;
        for (int i = n1 - 1; i >= 0; i--){
            if(num1[i]=='-')
              continue;
            int carrier = 0;
            int n1 = num1[i] - '0';
            i_n2 = 0;
            for (int j = n2 - 1; j >= 0; j--){
                if(num2[j]=='-')
                   continue;
                int n2 = num2[j] - '0';     

                int sum = n1 * n2 + result[i_n1 + i_n2] + carrier;
                carrier = sum / 10;
                result[i_n1 + i_n2] = sum % 10;

                i_n2++;
            }
            if (carrier > 0)
                result[i_n1 + i_n2] += carrier;

            i_n1++;
        }
        int i = result.size() - 1;
        while (i>=0 && result[i] == 0) i--;
        if(i == -1) return "0";
        string s = "";
        string p;
        
        while (i >= 0) s += std::to_string(result[i--]);
        if(mul==-1)
        { p="-"; p.append(s); }
        else
           p.append(s);
        return p;
    }
 
};
