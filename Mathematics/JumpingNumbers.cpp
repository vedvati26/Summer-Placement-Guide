class Solution {
  public:
    bool isjump(long long X)
    {
        int num1=X%10;
        X=X/10;
        while(X)
        {
            int num=X%10;
            if(abs(num-num1)!=1) return false;
            X=X/10;
            num1=num;
        }
        return true;
    }
    long long jumpingNums(long long X) {
        queue<long long>q;
        for(int i=1;i<10;i++)
        {
            q.push(i);
        }
        long long ans=0;
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            if(t>X)
            continue;
            ans=max(ans,t);
            int l=t%10;
            if(l!=0) q.push(t*10+(l-1));
            if(l!=9)q.push(t*10+(l+1));
        }
        return ans;
    }
};
