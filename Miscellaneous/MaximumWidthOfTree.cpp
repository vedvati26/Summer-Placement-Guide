/*  struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    
    void solve(Node *root,int lvl,map<int,int> &m){
        
        if(root == NULL){
            return;
        }
        
        m[lvl]++;
        
        solve(root->left,lvl+1,m);
        solve(root->right,lvl+1,m);
        
    }
    
    
    int getMaxWidth(Node* root) {

        // Your code here
        int ans = 0;
        map<int,int> m;
        solve(root,0,m);
        
        for(auto i : m){
            ans = max(ans,i.second);
        }
        
        return ans;
        
    }
};