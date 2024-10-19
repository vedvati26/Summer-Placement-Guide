class Solution {
  public:
  string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string res="";
        int i=0;
        int carry=0;
        while(i<min(num1.length(), num2.length())){
            int x=carry;
            x+=num1[i]-'0';
            x+=num2[i]-'0';
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
            i++;
        }
        while(i<num1.length()){
            int x=carry;
            x+=num1[i]-'0';
            // x+=num2[i]-'0';
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
            i++;
        }
        while(i<num2.length()){
            int x=carry;
            // x+=num1[i]-'0';
            x+=num2[i]-'0';
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
            i++;
        }
        while(carry){
            int x=carry;
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
        }
        reverse(res.begin(), res.end());

        return res;

    }
    bool isAdditiveSequence(string num) {
        // Your code here
        int n=num.length();
        if(n<3) return false;
        for(int i=1;i<=n/2;i++){
            for(int j=1;max(i,j)<=n-i-j;j++){
                string first=num.substr(0,i);
                string second=num.substr(i,j);
                
                if(first.length()>1 && first[i]=='0'){
                    break;
                }
                if(second.length()>1 && second[i]=='0'){
                    break;
                }
                
                int start=i+j;
                string sum;
                while(start<n){
                    sum=addStrings(first, second);
                    if(start+sum.length()>n || sum!=num.substr(start, sum.length())){
                        break;
                    }
                    first=second;
                    second=sum;
                    start+=sum.length();
                }
                if(start==n){
                    return true;
                }
            }
        }
        return false;
    }
};
/*// User function template for C++
class Solution {
  public:
 
    bool isAdditiveSequence(string n) {
        int a=0, b=0, t=0;
        for(int i=0; i<n.size(); i++){
            a*=10;
            a+=(n[i]-'0');
            b=0;
            
            for(int j=i+1; j<n.size(); j++){
                b*=10;
                b+=(n[j]-'0');
                int c=j+1;
                int ax=a, bx=b;
                while(c<n.size()){
                    
                int x=a+b;
               // cout<<i<<" "<<x<<endl;
                int l=0;
                int y=x;
                while(y){
                    y/=10;
                    l++;
                }
                
                if((c+l)>n.size()){
                    break;
                }
                int z=0;
                while(l--){
                    z*=10;
                    z+=(n[c]-'0');
                    c++;
                }
                
                if(z!=x){
                    break;
                }
                a=b;
                b=z;
                if(c==n.size()){
                    return true;
                }
                
                
                
                    
                    
                }
                
                a=ax;
                b=bx;
                
                
                
                
                
            }
            
            
            
            
            
            
            
        }
        
        return false;
    }
}; */