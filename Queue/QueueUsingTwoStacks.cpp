void StackQueue :: push(int B)
{
    s1.push(B);
}
int StackQueue :: pop(){
        if(s2.empty())
        {
            if(s1.empty())
                return -1;
            while(!s1.empty())
            {
                int r=s1.top();
                s1.pop(); 
                s2.push(r);
            }
        }
        int k=s2.top();
        s2.pop();
        return k;
    }
