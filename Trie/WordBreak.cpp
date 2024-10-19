class node {
    public:
    vector<node*> childs;
    bool isword;
    node(){
        childs.resize(26,NULL);
        isword=false;
    }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int check(string &a, int j, node* root){
        if(j>=a.size()) return true;
        node *ptr=root;
        for(int i=j;i<a.size();i++){
            if(ptr->childs[a[i]-'a']==NULL) return false;
            ptr=ptr->childs[a[i]-'a'];
            if(ptr->isword && check(a,i+1,root)) return true;
        }
        return ptr->isword;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        node *root=new node();
        for(auto s:B){
            node *ptr=root;
            for(auto i:s){
                if(ptr->childs[i-'a']==NULL){
                    ptr->childs[i-'a']=new node();
                }
                ptr=ptr->childs[i-'a'];
            }
            ptr->isword=true;
        }
        return check(A,0,root);
    }
};