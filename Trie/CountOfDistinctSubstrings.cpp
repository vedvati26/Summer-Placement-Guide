struct Node{
    Node* links[26];
    bool containKey(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};

int countDistinctSubstring(string s)
{
    //Your code here
    int cnt=0;
    Node* root=new Node();
    for(int i=0;i<s.length();i++){
        Node*node=root;
        for(int j=i;j<s.length();j++){
            if(!node->containKey(s[j])){
                cnt++;
                node->put(s[j],new Node());
            }
            node=node->get(s[j]);
        }
    }
    return cnt+1;
}