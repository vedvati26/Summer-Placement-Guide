Node* buildTree(int in[], int lev[], int iStart, int iEnd,int n)
{
    queue<pair<Node*,pair<int,int>>> q;
    
    map<int,int> inMap;
    for(int i=0;i<n;i++){
        inMap[in[i]] = i;
    }
    
    int ind=1;
    Node* root = new Node(lev[0]);
    q.push({root,{0,n-1}});
    

    while(ind<n){
        auto it = q.front();
        q.pop();
        
        auto node = it.first;
        int val = node->key;
        int left = it.second.first, right = it.second.second;
        
        bool leftFound=false;
        int inInd=inMap[lev[ind]];
        if(inInd>=left && inInd<=right){
            if(inInd<inMap[val]){
                leftFound = true;
                node->left = new Node(lev[ind]);
                q.push({node->left, {left, inMap[val]-1}});
                ind++;
            } else if(inInd>inMap[val]){
                node->right = new Node(lev[ind]);
                q.push({node->right, {inMap[val]+1, right}});
                ind++;
            }
        }
        
        inInd=inMap[lev[ind]];
        if(leftFound && ind<n){
            if(inInd>=left && inInd<=right && inInd>inMap[val]){
                node->right = new Node(lev[ind]);
                q.push({node->right, {inMap[val]+1, right}});
                ind++;
            }
        }    
    }   
    
    
    return root;
}