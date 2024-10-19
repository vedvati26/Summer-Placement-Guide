class Solution{
public:
    bool static comp(val fst,val sec){
        return fst.second<sec.second;
    }
    int maxChainLen(struct val p[],int n){
        sort(p,p+n,comp);
        
        int ans=0;
        int prev=-1e9;
        for(int i=0;i<n;i++){
            if(p[i].first>prev){
                prev=p[i].second;
                ans++;
            }
        }
        return ans;
    }
};
