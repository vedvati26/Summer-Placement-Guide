class TrieNode{
    public:
    int data;
    TrieNode* children[2];
    bool isTerminal;
    TrieNode(int digit){
        data = digit;
        isTerminal = false;
        for(int i=0; i<2; i++){
            children[i] = false;
        }
    }
};

class Trie{
    TrieNode* root;
    public:  
    Trie(int data){
        root = new TrieNode(data);
    }
    
    void insertUtil(TrieNode* root,int M[],int size,int i,bool &distinct){
        if(i==size){
            root->isTerminal = true;
            return;
        }    
        
        int index = M[i];
        TrieNode* child;
        if(root->children[index]){
            child = root->children[index];
        }
        else{
            child = new TrieNode(M[i]);
            distinct = true;
            root->children[index] = child;
        }
        insertUtil(child,M,size,i+1,distinct);
    }
    
    void insert(int M[],int size,bool &distinct){
        int i = 0;
        insertUtil(root,M,size,i,distinct);
    }
    
};

class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        Trie* t = new Trie(-1);
        vector<vector<int>>ans;
        for(int i=0; i<row; i++){
            bool distinct = false;
            t->insert(M[i],col,distinct);
            if(distinct){
                vector<int>temp;
                for(int j=0; j<col; j++){
                    temp.push_back(M[i][j]);
                }   
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};