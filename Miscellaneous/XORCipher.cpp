class Solution{   
public:
    string deCypher(string S){
                int n=S.length();
        // Plain text variable
        char p[n/2+1];
        int q=n/2;
        auto x=0,y=0;
        // Loop for loop from the end to 
        // the mid section of the string 
        for(int i=n-1;i>(n/2)-1;i--)
        {
            int dec_val=0;
            // calculation of the plaintext digit 
        	if ((S[i])>='0' && (S[i])<='9')
    			dec_val = ((S[i]) - 48);
            else if (S[i]>='A' && S[i]<='F')
            	dec_val = ((S[i]) - 55);
            y=x^dec_val;
            // calculation of XOR chain
            x=x^y;
            if( y>=10 && y<=15)
                p[q]=y+55;
            else
                p[q]=y+ 48;
            q--;
        }
        // storing the answer in a variable
        string ans="";
        for(int i=0;i<=n/2;i++)
            ans = ans + p[i];
        return ans;
    }
};